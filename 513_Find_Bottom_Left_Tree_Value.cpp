#include <algorithm>
#include "TreeNode.hpp"

#define CHILD_EXIST true
#define NO_CHILD false

class Solution 
{
public:
    std::pair<int, int> depthAndVal;
    
    int findBottomLeftValue(TreeNode* root) 
    {
        this->depthAndVal = {0, root->val};
        trace(root, 0);
        return this->depthAndVal.second;        
    }

    bool trace(TreeNode* pNode, int depth)
    {
        if(pNode == nullptr)
        {
            return NO_CHILD;
        
        }
        bool leftChild = trace(pNode->left, depth+1);
        bool rightChild = trace(pNode->right, depth+1);

        if(!leftChild && !rightChild && depth > this->depthAndVal.first)
        {
            this->depthAndVal = {depth, pNode->val};
        }
        
        return CHILD_EXIST;
    }
};