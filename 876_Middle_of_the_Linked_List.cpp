#include "ListNode.hpp"

class Solution 
{
public:
    int target;
    ListNode* ret;

    ListNode* middleNode(ListNode* head) 
    {
        trace(head, 0);
        return this->ret;        
    }

    void trace(ListNode* pNode, int deepth)
    {
        if(pNode == nullptr)
        {
            this->target = deepth/2 + 1;
            return;
        }
        ++deepth;
        trace(pNode->next, deepth);
        if(deepth == this->target)
        {
            this->ret = pNode;
        }
    }
};