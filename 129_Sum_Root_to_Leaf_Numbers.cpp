#include "TreeNode.hpp"


class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        int current_sum = 0;
        trace(root, sum, current_sum);
        return sum;       
    }

    void trace(TreeNode* pNode, int& sum, int current_sum)
    {
        current_sum *= 10;
        current_sum += pNode->val;
        
        if(pNode->left == nullptr && pNode->right == nullptr){
            sum += current_sum;		
            return;
        }

        if(pNode->left != nullptr){
            trace(pNode->left, sum, current_sum);
        }

        if(pNode->right != nullptr){
            trace(pNode->right, sum, current_sum);
        }
    }

};
