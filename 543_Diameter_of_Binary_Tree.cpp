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
    int ret;
    int diameterOfBinaryTree(TreeNode* root) 
    {
        this->ret = 0;
        this->recursiveTrace(root);
        return this->ret;
        
    }
    int recursiveTrace(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return 0;
        }
        int left = recursiveTrace(pNode->left);
        int right = recursiveTrace(pNode->right);
        this->ret = std::max(this->ret, left+right);
        return std::max(left, right)+1;
    }
};