#include <iostream>
#include <algorithm>
#include "TreeNode.hpp"

class Solution 
{
public:
    int start;
    int longestSubOfStart;
    int longestBeforeStart;

    int amountOfTime(TreeNode* root, int start) 
    {
        this->start = start;
        this->longestBeforeStart = 0;
        recursive_trace(root);
        return std::max(this->longestBeforeStart, this->longestSubOfStart);       
    }    

    std::pair<bool, int> recursive_trace(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return {false, -1};
        }

        auto left = recursive_trace(pNode->left);
        auto right = recursive_trace(pNode->right);

        if(pNode->val == this->start)
        {
            this->longestSubOfStart = std::max(left.second, right.second)+1;
            return {true, 0};
        }
        else
        {
            if(left.first == true)
            {
                this->longestBeforeStart = std::max(this->longestBeforeStart, left.second+right.second+2);
                return {true, left.second+1};
            }
            else if(right.first == true)
            {
                this->longestBeforeStart = std::max(this->longestBeforeStart, left.second+right.second+2);
                return {true, right.second+1};
            }
            else
            {
                return {false, std::max(left.second, right.second)+1};
            }         
        }
    }

};