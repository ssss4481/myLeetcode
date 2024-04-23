#include <algorithm>
#include "TreeNode.hpp"

class Solution {
public:
    int ret;

    int maxPathSum(TreeNode* root) {
        this->ret = INT_MIN;    
        optimal_result(root);
        return this->ret;
    }

    int optimal_result(TreeNode* pNode){
        if(pNode == nullptr){
            return 0;
        }
        int left = optimal_result(pNode->left);
        int right = optimal_result(pNode->right);
        this->ret = std::max({left+right+pNode->val, left+pNode->val, right+pNode->val, pNode->val, this->ret});
        return std::max({left+pNode->val, right+pNode->val, pNode->val, 0});
    }
};