#include "TreeNode.hpp"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        if(root->val == key && root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        findAndModify(root, nullptr, key);
        if(root->val == key){
            TreeNode* new_root = root->left;
            delete root;
            root = new_root;            
        }
        return root;
    }

    void findAndModify(TreeNode* pNode, TreeNode* parent, int key){
        if(pNode->val == key){
            if(pNode->left == nullptr && pNode->right == nullptr){
                delete pNode;
                if(parent->val > key){
                    parent->left = nullptr;
                }else{
                    parent->right = nullptr;
                }
            }else{
                findSuccessorAndModify(pNode, parent);
            }
        }else{
            if(key < pNode->val && pNode->left != nullptr){
                findAndModify(pNode->left, pNode, key);
            }else if(key > pNode->val && pNode->right != nullptr){
                findAndModify(pNode->right, pNode, key);
            }
        }
    }

    void findSuccessorAndModify(TreeNode* target, TreeNode* parent){
        TreeNode* successor;
        if(target->right != nullptr){
            if(target->right->left == nullptr){
                successor = target->right;
                target->val = successor->val;
                target->right = successor->right;
                delete successor;
            }else{
                TreeNode* prev = target->right;
                successor = prev->left;
                while(successor->left != nullptr){
                    prev = prev->left;
                    successor = successor->left;
                }
                prev->left = successor->right;
                target->val = successor->val;
                delete successor;
            }
        }else{
            if(parent != nullptr){//successor is parent
                if(target->val < parent->val){//target is left child
                    parent->left = target->left;
                }else{
                    parent->right = target->left;
                }
                delete target;
            }
        }
    }
};