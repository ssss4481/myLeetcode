#include <vector>
#include "ListNode.hpp"
#include "TreeNode.hpp"
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution 
{
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        vector<int> nums;
        while(head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }

        int lo = 0;
        int hi = nums.size()-1;
        int mid = (lo + hi)/2;
        auto p = new TreeNode(nums[mid]);
        p->left = recursiveBuild(lo, mid-1, nums);
        p->right = recursiveBuild(mid+1, hi, nums);

        return p;        
    }
    TreeNode* recursiveBuild(int lo, int hi, vector<int>& nums)
    {
        if(lo > hi)
        {
            return nullptr;
        }
        int mid = (lo+hi)/2;
        auto pCurrentNode = new TreeNode(nums[mid]);
        pCurrentNode->left = recursiveBuild(lo, mid-1, nums);
        pCurrentNode->right = recursiveBuild(mid+1, hi, nums);
        return pCurrentNode;
    }
};