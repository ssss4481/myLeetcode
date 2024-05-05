#include "ListNode.hpp"

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while(node->next != nullptr){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete node;
    }
};