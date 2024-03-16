#include "ListNode.hpp"
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
    ListNode* target;
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        this->target = nullptr;
        traceAndRemove(head, n);
        if(this->target == nullptr)
        {
            auto ret = head->next;
            delete head;
            return ret;
        }
        else
        {            
            auto rmTarget = this->target->next;
            this->target->next = this->target->next->next;
            delete rmTarget;
        }        
        return head;
    }
    int traceAndRemove(ListNode* p, const int& n)
    {
        if(p->next == nullptr)
        {
            return 1;            
        }
        int ret = traceAndRemove(p->next, n);
        if(ret == n)
        {
            this->target = p;
        }        
        return ret + 1;
    }
};