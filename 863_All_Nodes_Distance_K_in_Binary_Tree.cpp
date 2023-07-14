#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Solution 
{
private:
    vector<int> ret;
    vector<TreeNode*> targetToRoot;


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        bool found = false;
        DFS(root, target, found);

        int distance = 0;
        DFSwithDistance(target, nullptr, distance, k);
        for(int i = 1; i < targetToRoot.size(); ++i)
        {
            ++distance;
            DFSwithDistance(targetToRoot[i], targetToRoot[i-1], distance, k);
        }
        return this->ret;
    }

    void DFS(TreeNode* current, TreeNode* target, bool& found)
    {
        if(current == nullptr)
        {
            return;
        }

        if(current == target)
        {
            found = true;
            targetToRoot.push_back(target);
            return;
        }

        DFS(current->left, target, found);
        if(found)
        {
            targetToRoot.push_back(current);
            return;
        }        
        DFS(current->right, target, found);
        if(found)
        {
            targetToRoot.push_back(current);
            return;
        }       
    }

    void DFSwithDistance(TreeNode* current, TreeNode* avoid, int distance, const int& k)
    {
        if(current == nullptr || distance > k || current == avoid)
        {
            return;
        }
        if(distance == k)
        {
            ret.push_back(current->val);
            return;
        }
        DFSwithDistance(current->left, avoid, distance+1, k);
        DFSwithDistance(current->right, avoid, distance+1, k);
    }

};