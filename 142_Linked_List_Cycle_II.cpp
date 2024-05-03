#include "ListNode.hpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next ==nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        if(slow != fast){
            return nullptr;
        }

        ListNode* t = head;
        while(t != slow){
            t = t->next;
            slow = slow->next;
        }
        return t;
    }
};