#include <vector>
#include "TreeNode.hpp"

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        trace(root, res);
        return res;
    }

    void trace(TreeNode* pNode, std::vector<int>& res){
        if(pNode == nullptr){
            return;
        }
        res.push_back(pNode->val);
        trace(pNode->left, res);
        trace(pNode->right, res);
    }
};