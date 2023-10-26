#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include "TreeNode.hpp"

const int n = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public: 
    std::vector<int> ret;  
    std::vector<int> largestValues(TreeNode* root) 
    {
        std::vector<int> ret;        
        std::vector<TreeNode*> Q1;
        std::vector<TreeNode*> Q2;        
        
        Q1.push_back(root);        
        int depth = 0;
        while(!Q1.empty())
        {
            ret.push_back(INT_MIN);
            bool inValid = true;
            for(auto& pNode: Q1)
            {
                if(pNode == nullptr)
                {
                    continue;
                }
                inValid = false;
                ret[depth] = std::max(ret[depth], pNode->val);
                Q2.push_back(pNode->left);
                Q2.push_back(pNode->right);
            }
            if(inValid)
            {
                ret.pop_back();
            }
            Q1.clear();
            Q1.swap(Q2);
            ++depth;
        }     
        return ret;
    }

};



class Solution2 
{
public: 
    std::vector<int> ret;  
    std::vector<int> largestValues(TreeNode* root) 
    {
        this->ret = std::vector<int> ();        
        trace(1, root);
        return this->ret;
    }
    void trace(int depth, TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return;
        }

        if(depth > this->ret.size())
        {
            this->ret.push_back(pNode->val);
        }
        else
        {
            this->ret[depth-1] = std::max(this->ret[depth-1], pNode->val);
        }

        trace(depth+1, pNode->left);
        trace(depth+1, pNode->right);
    }
};