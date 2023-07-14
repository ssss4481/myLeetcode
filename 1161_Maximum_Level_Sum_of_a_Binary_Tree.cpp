#include <vector>
#include <climits>
#include <algorithm>
#include "TreeNode.hpp"

class Solution 
{
private:
    std::vector<int> levelSum;

public:
    void trace(TreeNode* node, int level)
    {
        if(node == nullptr)
        {
            return;
        }

        if(this->levelSum.size() < level + 1)
        {
            levelSum.push_back(0);
        }

        levelSum[level] += node->val;
        this->trace(node->left, level+1);
        this->trace(node->right, level+1);
    }

    int maxLevelSum(TreeNode* root) 
    {
        this->levelSum.push_back(INT_MIN);
        this->trace(root, 1);
        return std::max_element(this->levelSum.begin(), this->levelSum.end()) - this->levelSum.begin();
    }
};