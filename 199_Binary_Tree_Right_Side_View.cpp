#include <vector>
#include <queue>
#include "TreeNode.hpp"

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }

        TreeNode* current = root;
        std::queue<TreeNode*> Q1;
        Q1.push(root);

        while (!Q1.empty())
        {
            int levelRightMost;
            std::queue<TreeNode*> Q2;
            while (!Q1.empty())
            {
                TreeNode* front = Q1.front();
                Q1.pop();
                levelRightMost = front->val;
                if (front->left != nullptr)
                {
                    Q2.push(front->left);
                }
                if (front->right != nullptr)
                {
                    Q2.push(front->right);
                }
            }
            ret.push_back(levelRightMost);
            Q1.swap(Q2);
        }
        return ret;
    }
};
