#include "ListNode.hpp"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }

        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode* head;
        if (list1->val <= list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        auto tail = head;

        while (1)
        {
            if (list1 == nullptr)
            {
                tail->next = list2;
                list2 = nullptr;
                break;
            }

            if (list2 == nullptr)
            {
                tail->next = list1;
                list1 = nullptr;
                break;
            }

            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
                tail = tail->next;
            }
        }

        return head;
    }
};
