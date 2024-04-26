#include <vector>
#include <unordered_map>
#include "TreeNode.hpp"
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

int ans[100001];

class Solution {
public:
    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        memset(ans, 0, 100001*sizeof(int));
        Lfirst(root, -1, 0);
        Rfirst(root, -1, 0);
        std::vector<int> ret(queries.size());
        for(int i = 0; i < ret.size(); ++i){
            ret[i] = ans[queries[i]];
        }
        return ret;
    }

    int Lfirst(TreeNode* pNode, int prev_depth, int cur_depth){
        if(!pNode){
            return prev_depth;
        }
        ans[pNode->val] = std::max(ans[pNode->val], prev_depth);
        prev_depth = std::max(prev_depth, cur_depth);
        int left = Lfirst(pNode->left, prev_depth, cur_depth+1);
        prev_depth = std::max(prev_depth, left);
        int right = Lfirst(pNode->right, prev_depth, cur_depth+1);
        return std::max(prev_depth, right);
    }
    int Rfirst(TreeNode* pNode, int prev_depth, int cur_depth){
        if(!pNode){
            return prev_depth;
        }
        ans[pNode->val] = std::max(ans[pNode->val], prev_depth);     
        prev_depth = std::max(prev_depth, cur_depth);           
        int right = Rfirst(pNode->right, prev_depth, cur_depth+1);
        prev_depth = std::max(prev_depth, right);
        int left = Rfirst(pNode->left, prev_depth, cur_depth+1);
        return std::max(left, prev_depth);
    }    
};

//too slow

struct Subtree_Height{
    int left;
    int right;
    Subtree_Height(){}
    Subtree_Height(int _left, int _right){
        left = _left;
        right = _right;
    }
};

Subtree_Height node_info[100001];
int ans[100001];

class Solution1 {
public:
    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        trace(root, 0, node_info);
        pre_count(root->left, 1, node_info[root->val].right, node_info, ans);
        pre_count(root->right, 1, node_info[root->val].left, node_info, ans);
        std::vector<int> ret(queries.size());
        for(int i = 0; i < queries.size(); ++i){
            ret[i] = ans[queries[i]];
        }
        return ret;
    }


    int trace(TreeNode* pNode, int depth, Subtree_Height node_info[]){
        if(pNode == nullptr){
            return 0;
        }
        node_info[pNode->val].left = trace(pNode->left, depth+1, node_info);
        node_info[pNode->val].right = trace(pNode->right, depth+1, node_info);
        return std::max({depth, node_info[pNode->val].left, node_info[pNode->val].right});
    }

    void pre_count(TreeNode* pNode, int depth, int parent_included_best, Subtree_Height node_info[], int ans[]){
        if(pNode == nullptr){
            return;
        }
        ans[pNode->val] = parent_included_best;
        parent_included_best = std::max(parent_included_best, depth);
        pre_count(pNode->left, depth+1, std::max(parent_included_best, node_info[pNode->val].right), node_info, ans);
        pre_count(pNode->right, depth+1, std::max(parent_included_best, node_info[pNode->val].left), node_info, ans);
    }

};

class Solution1 {//TLE

public:
    std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
        const int root_val = root->val;
        std::unordered_map<int, Subtree_Height> node_info;
        std::unordered_map<int, int>  to_parent;
        std::unordered_map<int, TreeNode*>  to_node;

        std::vector<int> ret(queries.size());

        to_node[root_val] = root;
        int left = trace(root, root->left, 1, node_info, to_parent, to_node);
        int right = trace(root, root->right, 1, node_info, to_parent, to_node);
        node_info[root_val].left = left;
        node_info[root_val].right = right;

        for(int i = 0; i < queries.size(); ++i){
            int q = queries[i];
            int parent = to_parent[q];
            int subtree_height = 0;

            while(1){
                if(to_node[parent]->left != nullptr && to_node[parent]->left->val == q){
                    subtree_height = std::max(subtree_height, node_info[parent].right);
                }else if(to_node[parent]->right != nullptr && to_node[parent]->right->val == q){
                    subtree_height = std::max(subtree_height, node_info[parent].left);
                }     
                ++subtree_height;
                q = parent;
                if(q == root_val){
                    break;
                }
                parent = to_parent[q];                
            }

            ret[i] = subtree_height-1;
        }
        return ret;
    }

    int trace(TreeNode* parent, TreeNode* pNode, int depth, std::unordered_map<int, Subtree_Height>& node_info, std::unordered_map<int, int>&  to_parent, std::unordered_map<int, TreeNode*>&  to_node){
        if(pNode == nullptr){
            return 0;
        }
        to_parent[pNode->val] = parent->val;
        to_node[pNode->val] = pNode;
        int left = trace(pNode, pNode->left, depth+1, node_info, to_parent, to_node);
        int right = trace(pNode, pNode->right, depth+1, node_info, to_parent, to_node);
        node_info[pNode->val].left = left-depth;
        node_info[pNode->val].right = right-depth;
        return std::max({depth, left, right});
    }
    
};