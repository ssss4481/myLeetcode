#include "ListNode.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        ListNode* before_head = new ListNode(0);
        ListNode* tail = before_head;
        ListNode* candidate = head;
        trace(head, tail, 999);
        return before_head->next;
    }

    void trace(ListNode* cur, ListNode* tail, int prev_val){
        if(cur == nullptr){
            tail->next = nullptr;
            return;
        }

        if(cur->val != prev_val && (cur->next == nullptr || cur->next->val != cur->val)){
            tail->next = cur;
            tail = cur;
        }
        prev_val = cur->val;
        trace(cur->next, tail, prev_val);
    }
};