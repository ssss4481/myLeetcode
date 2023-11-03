#include <iostream>
#include <algorithm>
#include "TreeNode.hpp"

class Solution
{
public:
    int ans = 0;

    int averageOfSubtree(TreeNode* root) 
    {
        LRD(root);
        return this->ans;        
    }

    std::pair<int, int> LRD(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return std::make_pair(0, 0);
        }
        auto left = LRD(pNode->left);
        auto right = LRD(pNode->right);
        int sum = left.second + right.second + pNode->val;
        int count = left.first + right.first + 1;
        if(sum/count == pNode->val)
        {
            ++this->ans;            
        }
        return std::make_pair(std::move(count), std::move(sum));
    }
};