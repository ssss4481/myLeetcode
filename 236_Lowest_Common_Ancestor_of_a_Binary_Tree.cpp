#include <vector>
#include "TreeNode.hpp"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        DFSforP(root, p, path);
        path.push_back(nullptr);

        for(int i = path.size()-2; i >=0 ; --i){
            if(DFSforQ(path[i], q, path[i+1])){
                return path[i];
            }
        }
        return nullptr;
    }

    bool DFSforP(TreeNode* pNode, const TreeNode* p, vector<TreeNode*>& path){
        if(pNode == nullptr){
            return false;
        }
        path.push_back(pNode);
        if(pNode == p || DFSforP(pNode->left, p, path) || DFSforP(pNode->right, p, path)){
            return true;
        }
        path.pop_back();
        return false;
    }

    bool DFSforQ(TreeNode* pNode, const TreeNode* q, const TreeNode* ignoredNode){
        if(pNode == nullptr || pNode == ignoredNode){
            return false;
        }
        if(pNode == q){
            return true;
        }
        return DFSforQ(pNode->left, q, ignoredNode) || DFSforQ(pNode->right, q, ignoredNode);
    }



};