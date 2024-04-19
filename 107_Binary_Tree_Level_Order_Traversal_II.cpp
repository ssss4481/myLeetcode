#include <queue>
#include <vector>
#include "TreeNode.hpp"

class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        std::vector<std::vector<int>> ret;
        std::queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            std::queue<TreeNode*> Q2;
            ret.push_back({});
            while(!Q.empty()){
                TreeNode* pNode = Q.front();
                ret.back().push_back(pNode->val);
                if(pNode->left != nullptr){
                    Q2.push(pNode->left);
                }
                if(pNode->right != nullptr){
                    Q2.push(pNode->right);
                }
                Q.pop();
            }
            Q.swap(Q2);
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};