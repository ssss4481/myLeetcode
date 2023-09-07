#include <algorithm>
#include <iostream>
#include "ListNode.hpp"

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)     
    {
        if(head->next == nullptr || left == right)
        {
            return head;
        }
        ListNode* beforeLeftNode = nullptr;
        ListNode* leftNode;

        int pos = 1;
        if(left == 1)
        {
            leftNode = head;
        }
        else
        {
            ListNode* currentNode = head;
            while(1)
            {
                if(pos+1 == left)
                {
                    beforeLeftNode = currentNode;
                    leftNode = currentNode->next;
                    ++pos;
                    break;
                }
                currentNode = currentNode->next;
                ++pos;
            }
        }


        if(right-left > 1)
        {
            ListNode* opLeftNode = leftNode;
            ListNode* opMidNode = opLeftNode->next;
            ListNode* opRightNode = opMidNode->next;

            while(pos <= right-2)
            {
                opMidNode->next = opLeftNode;
                opLeftNode = opMidNode;
                opMidNode = opRightNode;
                opRightNode = opMidNode->next;
                ++pos;
            }

            leftNode->next = opMidNode->next;
            if(beforeLeftNode != nullptr)
            {
                beforeLeftNode->next = opMidNode;
            }
            opMidNode->next = opLeftNode;
            if(left == 1)
            {
                head = opMidNode;
            }
        }
        else
        {
            ListNode* rightNode = leftNode->next;
            if(beforeLeftNode != nullptr)
            {
                beforeLeftNode->next = leftNode->next;
            }
            leftNode->next = rightNode->next;
            rightNode->next = leftNode;            

            if(left == 1)
            {
                head = rightNode;
            }

        }

        return head;
    }
};