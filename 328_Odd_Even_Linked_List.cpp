#include "ListNode.hpp"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        auto FirstGroupHead = head;
        auto SecondGroupHead = head->next;

        auto FirstGroupTail = FirstGroupHead;
        auto SecondGroupTail = SecondGroupHead;

        bool ToFirstGroup = true;
        auto processNode = SecondGroupTail->next;
        while(processNode != nullptr){
            if(ToFirstGroup){
                FirstGroupTail->next = processNode;
                FirstGroupTail = processNode;
            }
            else
            {
                SecondGroupTail->next = processNode;
                SecondGroupTail = processNode;
            }
            ToFirstGroup = !ToFirstGroup;
            processNode = processNode->next;
        }
        FirstGroupTail->next = SecondGroupHead;
        SecondGroupTail->next = nullptr;
        return FirstGroupHead;
    }
};