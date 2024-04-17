#include <string>
#include "TreeNode.hpp"


class Solution {
public:
    std::string smallestFromLeaf(TreeNode* root) {
        std::string ret = "";
        std::string current = "";
        trace(root, ret, current);
        return ret;
    }

    void trace(TreeNode* pNode, std::string& ret, std::string& current){
        current.push_back(('a'+char(pNode->val)));

        if(pNode->left == nullptr && pNode->right == nullptr){            
            std::reverse(current.begin(), current.end());
            if(ret == "" ||  current < ret){
                ret = current;
            }
            std::reverse(current.begin(), current.end());
        }

        if(pNode->left != nullptr){
            trace(pNode->left, ret, current);
        }

        if(pNode->right != nullptr){
            trace(pNode->right, ret, current);
        }

        current.pop_back();
    }
};