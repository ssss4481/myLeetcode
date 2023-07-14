#include <queue>
#include <iostream>
#include "TreeNode.hpp"

class Solution 
{
public:
    bool isLeaf(TreeNode* pNode)
    {
        return (pNode->left == nullptr) && (pNode->right == nullptr);
    }

    void parse(std::queue<TreeNode*>& Q2, TreeNode* pNode)
    {
        if(pNode->left != nullptr)
        {
            Q2.push(pNode->left);
        }

        if(pNode->right != nullptr)
        {
            Q2.push(pNode->right);
        }
    }

    int minDepth(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }

        std::queue<TreeNode*> Q1;
        std::queue<TreeNode*> Q2;
        int depth = 1;
        Q1.push(root);

        while (!Q1.empty())
        {
            while (!Q1.empty())
            {
                TreeNode*& pNode = Q1.front();
                if(isLeaf(pNode))
                {
                    return depth;
                }
                parse(Q2, pNode);
                Q1.pop();
            }           
            ++depth;
            Q1.swap(Q2);
        } 

        return -1;        
    }
};


