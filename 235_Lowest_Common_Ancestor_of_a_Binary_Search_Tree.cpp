#include "TreeNode.hpp"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int& pval = p->val;
        int& qval = q->val;

        auto current_node = root;
        while(current_node != nullptr){
            if(current_node == p){
                return p;
            }
            if(current_node == q){
                return q;
            }

            int& current_val = current_node->val;
            if(current_val > pval && current_val > qval){
                current_node = current_node->left;
            }
            else if(current_val < pval && current_val < qval){
                current_node = current_node->right;
            }
            else{
                return current_node;
            }
        }
        return nullptr;
    }
};