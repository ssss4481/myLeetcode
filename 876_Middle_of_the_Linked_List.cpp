#include "ListNode.hpp"


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            return head->next;
        }

        auto oneStep = head;
        auto twoStep = head;
        
        while(twoStep->next != nullptr && twoStep->next->next != nullptr){
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }

        if(twoStep->next == nullptr){
            return oneStep;
        }

        return oneStep->next;
    }
};


class Solution2 
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