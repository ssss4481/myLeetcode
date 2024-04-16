#include <iostream>
#include "ListNode.hpp"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        return recursiveSwap(head);
    }

    ListNode* recursiveSwap(ListNode* pNode){
        if(pNode == nullptr || pNode->next == nullptr){
            return pNode;
        }

        auto first = pNode;
        auto second = pNode->next;

        auto nextPairFirst = recursiveSwap(second->next);
        
        second->next = first;
        first->next = nextPairFirst;

        return second;
    }
};


class Solution1 
{
public:
    void swap(ListNode* first, ListNode* second)
    {
        ListNode* temp = second->next;        
        second->next = first;
        first->next = temp;
    }


    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* fakeNode = new ListNode(0, head);
        ListNode* tailOfPreviousPair = fakeNode;
        ListNode* first = nullptr;
        ListNode* second = nullptr;     
        while(current != nullptr)
        {
            first = current;
            second = current->next;
            if(second == nullptr)
                break;
            if(first != nullptr && second != nullptr)
            {
                this->swap(first, second);
                tailOfPreviousPair->next = second;                
                if(tailOfPreviousPair == fakeNode)
                    head = second;
                tailOfPreviousPair = first;
                current = tailOfPreviousPair->next;
                first = nullptr;
                second = nullptr;
            }
        }
        delete fakeNode;
        return head;        
    }
};
