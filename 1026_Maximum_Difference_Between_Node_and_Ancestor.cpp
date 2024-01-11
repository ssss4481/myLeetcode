#include <cmath>
#include <algorithm>
#include <iostream>
#include "TreeNode.hpp"


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    int maxDiff = 0;

    int maxAncestorDiff(TreeNode* root) 
    {
        trace(root, root->val, root->val);
        return this->maxDiff;        
    }

    void trace(TreeNode* pNode, int maxAncestor, int minAncestor)    
    {
        if(pNode == nullptr)
        {
            return;
        }
        this->maxDiff = std::max({std::abs(maxAncestor - pNode->val), std::abs(minAncestor - pNode->val), this->maxDiff});
        maxAncestor = std::max(pNode->val, maxAncestor);
        minAncestor = std::min(pNode->val, minAncestor);
        trace(pNode->left, maxAncestor, minAncestor);
        trace(pNode->right, maxAncestor, minAncestor);
    }
};