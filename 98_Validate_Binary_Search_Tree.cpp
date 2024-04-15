#include "TreeNode.hpp"

class Solution {
public:
    long long previous;

    bool isValidBST(TreeNode* root) 
    {
        this->previous = INT_MIN-1LL;
        return LDR(root);
    }

    bool LDR(TreeNode* pNode)
    {
        if(pNode == nullptr){
            return true;
        }
        if(!LDR(pNode->left)){
            return false;
        }
        if(this->previous >= pNode->val){
            return false;
        }
        this->previous = pNode->val;
        return LDR(pNode->right);
    }
};