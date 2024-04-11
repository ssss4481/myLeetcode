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
    int ans;

    int kthSmallest(TreeNode* root, int k) 
    {
        LDR(root, k);
        return this->ans;
    }

    int LDR(TreeNode* pNode, int& k)
    {
        if(pNode == nullptr)
        {
            return -1;
        }

        if(LDR(pNode->left, k) == 0)
        {
            return 0;
        }
        if(--k == 0)
        {
            this->ans = pNode->val;
            return 0;
        }
        return LDR(pNode->right, k);
    }
};