#include <iostream>
#include "ListNode.hpp"

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
    bool hasCycle(ListNode *head) 
    {
        ListNode* oneStep = head;
        ListNode* twoStep = head;
        while(twoStep != nullptr && twoStep->next != nullptr)
        {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            if(oneStep == twoStep)
            {
                return true;
            }
        }             
        return false;        
    }
};
