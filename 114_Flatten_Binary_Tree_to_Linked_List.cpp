#include "TreeNode.hpp"

class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }

    TreeNode* flat(TreeNode* pNode){
        if(pNode == nullptr){
            return nullptr;
        }
        auto left = pNode->left;
        auto right = pNode->right;
        pNode->left = nullptr;

        if(left != nullptr){
            pNode->right = left;
            auto suc = flat(left);
            suc->left = nullptr;
            if(right == nullptr){
                return suc;
            }else{
                suc->right = right;
                return flat(right);
            }
        }else if(right != nullptr){
            pNode->right = right;
            return flat(right);
        }

        return pNode;
    }
};