#include "TreeNode.hpp"

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        return trace(root, 1);
    }

    int trace(TreeNode* pNode, int depth)
    {
        if (pNode == nullptr)
        {
            return 0;
        }
        return std::max({trace(pNode->left, depth + 1), trace(pNode->right, depth + 1), depth});
    }
};
