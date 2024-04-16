#include "TreeNode.hpp"

class Solution { //iterative
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }

        if(root->left == nullptr || root->right == nullptr){
            return false;
        }

        std::queue<TreeNode*> LQ;        
        std::queue<TreeNode*> RQ;

        LQ.push(root->left);
        RQ.push(root->right);
        while(!LQ.empty() && !RQ.empty()){
            auto L = LQ.front();
            LQ.pop();
            auto R = RQ.front();
            RQ.pop();

            if(L != nullptr && R != nullptr){
                if(L->val != R->val){
                    return false;
                }
                LQ.push(L->left);
                LQ.push(L->right);
                RQ.push(R->right);
                RQ.push(R->left);                
            }else if(L == nullptr && R != nullptr){
                return false;
            }else if(L != nullptr && R == nullptr){
                return false;
            }
        }
        return true;
    }
};


class Solution2//recursive
{
public:
    bool isMirror(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == nullptr && node2 == nullptr)
            return true;
        if((node1 == nullptr) ^ (node2 == nullptr) || node1->val != node2->val)
            return false;
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
    bool isSymmetric(TreeNode* root)
    {
        return isMirror(root->left, root->right);
    }
};