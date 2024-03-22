#include "ListNode.hpp"
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    ListNode* front;

    bool isPalindrome(ListNode* head) 
    {
        this->front = head;
        return check(head);
    }
    bool check(ListNode* pNode)
    {
        if(pNode == nullptr)
        {
            return true;
        }
        if(!check(pNode->next) || pNode->val != this->front->val)
        {
            return false;
        }
        this->front = this->front->next;
        return true;        
    }
};