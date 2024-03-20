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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* lo;
        ListNode* hi;
        ListNode* temp = list1;
        int deepth = 0;
        while(true)
        {
            if(deepth == a-1)
            {
                lo = temp;
            }

            if(deepth == b+1)
            {
                hi = temp;
                break;
            }
            ++deepth;
            temp = temp->next;
        }

        lo->next = list2;
        while(list2->next != nullptr)
        {
            list2 = list2->next;
        }
        list2->next = hi;
        return list1;
    }
};