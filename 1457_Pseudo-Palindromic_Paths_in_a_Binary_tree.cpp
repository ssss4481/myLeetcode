#include "TreeNode.hpp"
#include <vector>
#include <bitset>
using namespace std;

class Solution {
    public:
        bool check(const vector<bool> &record, int ans)
        {
            int count = 0;
            for(int i = 1; i < 10; ++i)
            {
                if(record[i])
                    ++count;
            }

            return (count == ans);
        }

        
        void DFS(TreeNode* pNode, vector<bool> &record, bool odd, int& counter)
        {
            if(pNode == nullptr)
                return;

            record[pNode->val] = !(record[pNode->val]);

            if(pNode->left == nullptr && pNode->right == nullptr)
            {
                if(odd)
                {
                    if(check(record, 1))
                        ++counter;
                }
                else
                {
                    if(check(record, 0))
                        ++counter;
                }
                record[pNode->val] = !(record[pNode->val]);
                return;
            }

            DFS(pNode->left, record, !odd, counter);
            DFS(pNode->right, record, !odd, counter);
            record[pNode->val] = !(record[pNode->val]);

        }
        
        int pseudoPalindromicPaths (TreeNode* root) 
        {
            int counter = 0;
            bool odd = true;
            vector<bool> record(10, false);
            
            DFS(root, record, odd, counter);

            return counter;
        }
};




class Solution2 {
    public:
        
        void DFS(TreeNode* pNode, bitset<10> record, int& counter)
        {
            if(pNode == nullptr)
                return;

            record.flip(pNode->val);

            if(pNode->left == nullptr && pNode->right == nullptr)
            {
                if(record.count() < 2)
                    ++counter;
                return;
            }

            DFS(pNode->left, record, counter);
            DFS(pNode->right, record, counter);
        }
        
        int pseudoPalindromicPaths (TreeNode* root) 
        {
            int counter = 0;
            bitset<10> record;
            record.reset();

            DFS(root, record, counter);

            return counter;
        }
};


class Solution1 {
    public:
        
        void DFS(TreeNode* pNode, int record, bool odd, int& counter, int bitArr[])
        {
            if(pNode == nullptr)
                return;

            if((record & bitArr[pNode->val]) == bitArr[pNode->val])
                record -= bitArr[pNode->val];
            else
                record += bitArr[pNode->val];


            if(pNode->left == nullptr && pNode->right == nullptr)
            {
               int count = 0;
               while(record != 0)
               {
                    record &= (record-1);
                    ++count;
               }
                if(count < 2)
                    ++counter;
                return;
            }

            DFS(pNode->left, record, !odd, counter, bitArr);
            DFS(pNode->right, record, !odd, counter, bitArr);
        }


        int pseudoPalindromicPaths (TreeNode* root) 
        {
            int bitArr[10];
            int counter = 0;
            int record = 0;
            bool odd = true;

            bitArr[1] = 1;
            for(int i = 2; i <= 9; ++i)
            {
                bitArr[i] = bitArr[i-1] << 1; 
            }
            
            DFS(root, record, odd, counter, bitArr);

            return counter;
        }
};



int main()
{
    return 0;
}