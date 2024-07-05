#include "ListNode.hpp"
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* cur = head;

        while(cur->next != nullptr){

            ListNode* mergeTarget = cur->next;
            ListNode* temp;

            while(mergeTarget->val != 0){
                cur->val += mergeTarget->val;
                temp = mergeTarget->next;
                delete mergeTarget;
                mergeTarget = temp;
            }

            if(mergeTarget->next != nullptr){
                cur->next = mergeTarget;
                cur = mergeTarget;
            }else{//mergeTarget is the last node.
                cur->next = nullptr;
                delete mergeTarget;
            }
        }

        return head;
    }
};