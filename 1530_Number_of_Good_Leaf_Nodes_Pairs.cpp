#include <unordered_map>
#include <iostream>
#include <vector>
#include "TreeNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;


class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if(distance <= 1){
            return 0;
        }
        int pair = 0;
        trace(root, distance, pair);
        return pair;
    }

    vector<int> trace(TreeNode* root, const int distance, int& pair){

        vector<int> ret(distance, 0);

        if(root == nullptr){
            return ret;
        }

        if(root->left == nullptr && root->right == nullptr){
            ret[1] = 1;
            return ret;
        }                

        auto left_info = trace(root->left, distance, pair);
        auto right_info = trace(root->right, distance, pair);

        int presum = 0;

        for(int i = distance-1; i > 0; i--){
            presum += right_info[distance-i];
            pair += left_info[i] * presum;
        }
        
        auto& tree_info = left_info;

        for(int i = distance-1; i > 0; i--){
            tree_info[i] = left_info[i-1] + right_info[i-1];
        }

        return tree_info;
    }
};

class Solution1 {
public:
    int distance;
    unordered_map<TreeNode*, TreeNode*> toParent;

    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leaves;
        trace(root, leaves);

        this->distance = distance;
        int pair = 0;

        for(auto& leaf: leaves){
            DFS(nullptr, leaf, 0, pair);
        }
        return pair/2;
    }

    void trace(TreeNode* root, vector<TreeNode*>& leaves){

        if(root->left == nullptr && root->right == nullptr){
            leaves.emplace_back(root);
            return;
        }

        if(root->left != nullptr){
            toParent[root->left] = root;
            trace(root->left, leaves);
        }

        if(root->right != nullptr){
            toParent[root->right] = root;
            trace(root->right, leaves);
        }
    }

    void DFS(TreeNode* previous, TreeNode* current, int depth, int& pair){
        if(depth > distance || current == nullptr){
            return;
        }

        if(depth > 0 && current->left == nullptr && current->right == nullptr){
            ++pair;
            return;
        }

        if(previous != toParent[current]){
            DFS(current, toParent[current], depth+1, pair);
        }

        if(previous != current->left){
            DFS(current, current->left, depth+1, pair);
        }

        if(previous != current->right){
            DFS(current, current->right, depth+1, pair);
        }                
        
    }
};
