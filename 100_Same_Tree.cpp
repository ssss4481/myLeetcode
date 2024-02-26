#include "TreeNode.hpp"

class Solution 
{
public:
    bool same;

    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        this->same = true;
        recursiveTrace(p, q);
        return this->same;
    }

    void recursiveTrace(TreeNode* p, TreeNode* q)
    {
        if(!this->same)
        {
            return;
        }
        
        if(this->isNullptr(p) != this->isNullptr(q))
        {
            this->same = false;
            return;
        }

        if(p != nullptr)
        {
            if(p->val !=  q->val)
            {
                this->same = false;
                return;                
            }
            this->recursiveTrace(p->left, q->left);
            this->recursiveTrace(p->right, q->right);
        }
    }

    bool isNullptr(TreeNode* pNode)
    {
        return pNode == nullptr;
    }
};