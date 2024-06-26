#include <vector>
#include <iostream>
#include "TreeNode.hpp"

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        vector<int> nums;
        nums.reserve(10000);
        trace(root, nums);
        return constructTree(nums, 0, static_cast<int>(nums.size())-1);
    }

    void trace(TreeNode* root, vector<int>& nums){
        if(root == nullptr){
            return;
        }
        trace(root->left, nums);
        nums.emplace_back(root->val);
        trace(root->right, nums);
    }

    TreeNode* constructTree(const vector<int>& nums, int lo, int hi){
        if(lo > hi){
            return nullptr;
        }
        int mid = (lo+hi)/2;
        TreeNode* current = new TreeNode(nums[mid]);
        current->left = constructTree(nums, lo, mid-1);
        current->right = constructTree(nums, mid+1, hi);
        return current;
    }

};