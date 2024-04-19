#include <vector>
#include "TreeNode.hpp"


class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        
        std::vector<std::vector<int>> ret;
        std::vector<TreeNode*> Q;

        Q.push_back(root);
        while(!Q.empty()){
            std::vector<TreeNode*> Q2;
            ret.push_back({});
            for(auto& pNode: Q){
                ret.back().push_back(pNode->val);
                if(pNode->left != nullptr){
                    Q2.push_back(pNode->left);
                }
                if(pNode->right != nullptr){
                    Q2.push_back(pNode->right);
                }
            }
            Q.swap(Q2);
        }

        for(int i = 1; i < ret.size(); i+=2){
            std::reverse(ret[i].begin(), ret[i].end());
        }

        return ret;
    }
};