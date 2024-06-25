#include "TreeNode.hpp"

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        trace(root);
        return root;        
    }

    int trace(TreeNode* root, int greaterSum=0){
        if(root == nullptr){
            return 0;
        }
        int right = trace(root->right, greaterSum);
        int left = trace(root->left, right + root->val + greaterSum);
        int ret = left + right + root->val;
        root->val += right + greaterSum;
        return ret;
    }
};