#include "ListNode.hpp"

class Solution
{
public:
    void setHeadTail(ListNode* &head, ListNode* &tail, ListNode* &target)
    {
        head = target;
        tail = target;
        target = target->next;
    }
    void concatenateTail(ListNode* &oldTail, ListNode* &newTail)
    {
        oldTail->next = newTail;
        oldTail = newTail;
        newTail = newTail->next;
    }

    int getValue(ListNode* target)
    {
        if(target == nullptr)
            return 101;//valid value is between -100~100
        return target->val;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        if(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
                this->setHeadTail(head, tail, list1);
            else
                this->setHeadTail(head, tail, list2);
        }
        else if(list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        else if(list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        while(list1 != nullptr || list2 != nullptr)
        {
            if(this->getValue(list1) <= this->getValue(list2))
                concatenateTail(tail, list1);
            else
                concatenateTail(tail, list2);
        }
        return head;
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}
