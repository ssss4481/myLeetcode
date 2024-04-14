#include "TreeNode.hpp"

#define LEFT 0
#define RIGHT 1
#define ROOT 2

class Solution 
{
public:
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        TraceAndSum(root, ROOT, sum);
        return sum;
    }

    void TraceAndSum(TreeNode* pNode, int NodeType, int& sum)
    {
        if(pNode == nullptr)
        {
            return;
        }

        if((pNode->left == nullptr) && (pNode->right == nullptr) && (NodeType == LEFT))
        {
            sum += pNode->val;
            return;
        }

        TraceAndSum(pNode->left, LEFT, sum);
        TraceAndSum(pNode->right, RIGHT, sum);
    }
};