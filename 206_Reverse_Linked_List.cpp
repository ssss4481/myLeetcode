#include <stack>
#include <iostream>
#include "ListNode.hpp"
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* next = head;

        while (next != nullptr)
        {
            ListNode* temp = prev;
            prev = next;
            next = next->next;
            prev->next = temp;
        }
        
        return prev;      
    }
};


class Solution1 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        std::stack<ListNode*> s;
        s.push(nullptr);
        while (head != nullptr)
        {
            s.push(head);
            head = head->next;
        }

        ListNode* ret = s.top();
        s.pop();
        ListNode* currentNode = ret;
        while(!s.empty())
        {
            currentNode->next = s.top();
            currentNode = s.top();
            s.pop();
        }
        return ret;      
    }
};
