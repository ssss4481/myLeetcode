#include <string>
#include "TreeNode.hpp"
#include <iostream>

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
    std::string ret;

    std::string tree2str(TreeNode* root) 
    {
        this->ret = "";
        DLR(root);
        return this->ret;        
    }
    void DLR(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return;
        }
        this->ret += std::to_string(pNode->val);
        if(pNode->left != nullptr)
        {
            this->ret += "(";
            DLR(pNode->left);
            this->ret += ")";                 
        }   
        if(pNode->right != nullptr)
        {
            if(pNode->left == nullptr)
            {
                this->ret += "()";
            }
            this->ret += "(";
            DLR(pNode->right);
            this->ret += ")";            
        }
    }
};