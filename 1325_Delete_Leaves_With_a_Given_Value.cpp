#include "TreeNode.hpp"


class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(remove(root, target)){
            return nullptr;
        }
        return root;
    }
    
    bool remove(TreeNode* pNode, int target){
        if(pNode == nullptr){
            return false;
        }

        if(remove(pNode->left, target)){
            pNode->left = nullptr;
        }
        if(remove(pNode->right, target)){
            pNode->right = nullptr;
        }

        if(pNode->val == target && pNode->left == nullptr && pNode->right == nullptr){
            return true;
        }
        return false;
    }

};