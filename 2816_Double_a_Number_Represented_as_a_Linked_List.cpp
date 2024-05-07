#include <iostream>
#include "ListNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = doubleList(head);
        
        if(carry == 0){
            return head;
        }

        ListNode* new_head = new ListNode(1, head);
        return new_head;
    }


    int doubleList(ListNode* pNode){
        if(pNode == nullptr){
            return 0;
        }
        int carry = doubleList(pNode->next);
        pNode->val *= 2;
        pNode->val += carry;

        int ret = 0;
        if(pNode->val >= 10){
            ret = 1;
            pNode->val %= 10;
        }

        return ret;
    }

};