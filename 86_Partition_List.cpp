#include <iostream>
#include "ListNode.hpp"

class Solution 
{
public:
    void append(ListNode* &tail, ListNode* newTail)
    {
        tail->next = newTail;
        tail = newTail;
    }

    ListNode* partition(ListNode* head, int x) 
    {
        if(head == nullptr)
        {
            return head;
        }

        ListNode* lessPartHead = new ListNode(0);
        ListNode* greaterOrEqualPartHead = new ListNode(0);
        ListNode* lessPartTail = lessPartHead;
        ListNode* greaterOrEqualPartTail = greaterOrEqualPartHead;

        while(head != nullptr)
        {
            if(head->val < x)
            {
                append(lessPartTail, head);
            }
            else
            {
                append(greaterOrEqualPartTail, head);
            }
            head = head->next;
        }

        ListNode* temp = lessPartHead;
        lessPartHead = lessPartHead->next;
        delete temp;
        temp = greaterOrEqualPartHead;
        greaterOrEqualPartHead = greaterOrEqualPartHead->next;
        if(greaterOrEqualPartTail == temp)
        {
            greaterOrEqualPartTail = nullptr;
        }
        delete temp;

        if(lessPartHead != nullptr)
        {
            lessPartTail->next = greaterOrEqualPartHead;
            if(greaterOrEqualPartTail != nullptr)
            {
                greaterOrEqualPartTail->next = nullptr;            
            }
            return lessPartHead;
        }
        else
        {
            return greaterOrEqualPartHead;
        }
    }
};




int main(int argc, char const *argv[])
{
    
    
    
    return 0;
}
