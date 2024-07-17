#include <vector>
#include <unordered_set>
#include "TreeNode.hpp"

class Solution 
{
public:
    std::vector<TreeNode*> ans;

    std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) 
    {
        std::unordered_set<int> hashSetFromToDelete(to_delete.begin(), to_delete.end());
        bool deleteRoot = hashSetFromToDelete.count(root->val) == 1;
        if(!deleteRoot)
        {
            this->ans.push_back(root);
        }
        deleteNodesRecursively(nullptr, root, hashSetFromToDelete);
        return this->ans;
    }

    void deleteNodesRecursively(TreeNode* parent, TreeNode* pNode, std::unordered_set<int>& to_delete)
    {
        if(pNode == nullptr)
        {
            return;
        }

        deleteNodesRecursively(pNode, pNode->left, to_delete);
        deleteNodesRecursively(pNode, pNode->right, to_delete);

        if(to_delete.count(pNode->val))
        {
            if(parent != nullptr && parent->left == pNode)
            {
                parent->left = nullptr;
            }
            else if(parent != nullptr && parent->right == pNode)
            {
                parent->right = nullptr;
            }

            if(pNode->left != nullptr)
            {
                this->ans.push_back(pNode->left);
            }
            if(pNode->right != nullptr)
            {
                this->ans.push_back(pNode->right);
            }            
            delete pNode;
        }
        return;
    }

};