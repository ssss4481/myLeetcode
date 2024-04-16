#include "TreeNode.hpp"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return trace(root, subRoot);
    }

    bool trace(TreeNode* pNode, TreeNode* subRoot){
        if(pNode == nullptr){
            return false;
        }
        if(pNode->val == subRoot->val && validate(pNode, subRoot)){
            return true;
        }
        return trace(pNode->left, subRoot) || trace(pNode->right, subRoot);
    }

    bool validate(TreeNode* pNode, TreeNode* pSubNode){
        if(pNode == nullptr && pSubNode == nullptr){
            return true;
        }
        if(pNode == nullptr || pSubNode == nullptr){
            return false;
        }
        return pNode->val == pSubNode->val && validate(pNode->left, pSubNode->left) && validate(pNode->right, pSubNode->right);
    }

};