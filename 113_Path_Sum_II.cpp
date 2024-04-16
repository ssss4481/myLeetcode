#include <vector>
#include "TreeNode.hpp"

class Solution {
public:
    std::vector<std::vector<int>> ret;

    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> path;
        trace(root, path, 0, targetSum);
        return this->ret;        
    }

    void trace(TreeNode* pNode, std::vector<int>& path, int sum, const int& targetSum){
        if(pNode == nullptr){
            return;
        }
        sum += pNode->val;
        path.push_back(pNode->val);
        if(pNode->left == nullptr && pNode->right == nullptr && sum == targetSum){
            this->ret.push_back(path);
            path.pop_back();
            return;
        }
        trace(pNode->left, path, sum, targetSum);
        trace(pNode->right, path, sum, targetSum);
        path.pop_back();
    }
};