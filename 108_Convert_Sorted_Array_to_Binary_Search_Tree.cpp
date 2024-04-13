#include <vector>
#include <iostream>
#include "TreeNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int mid = (nums.size()-1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        recursiveBuild(root, 0, mid-1, nums);
        recursiveBuild(root, mid+1, nums.size()-1, nums);
        return root;
    }
    void recursiveBuild(TreeNode* parent, int lo, int hi, vector<int>& nums)
    {
        if(lo > hi)
        {
            return;
        }
        int mid = (lo+hi)/2;
        auto pNode = new TreeNode(nums[mid]);
        if(nums[mid] > parent->val)
        {
            parent->right = pNode;
        }
        else
        {
            parent->left = pNode;
        }
        recursiveBuild(pNode, lo, mid-1, nums);
        recursiveBuild(pNode, mid+1, hi, nums);
    }

};