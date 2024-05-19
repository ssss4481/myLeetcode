#include <cmath>
#include "TreeNode.hpp"

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int cost = 0;
        trace(root, cost);
        return cost;
    }

    int trace(TreeNode* pNode, int& cost){
        if(pNode == nullptr){
            return 0;
        }

        int left = trace(pNode->left, cost);
        int right = trace(pNode->right, cost);

        cost += abs(left) + abs(right);
   
        return left + right + (pNode->val-1) ;
    }
};