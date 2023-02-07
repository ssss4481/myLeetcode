#include "TreeNode.hpp"

using namespace std;


class Solution
{
public:
    void invert(TreeNode* root)
    {
        if(root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }

    TreeNode* invertTree(TreeNode* root)
    {
        this->invert(root);
        return root;
    }
};