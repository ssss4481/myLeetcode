#include <iostream>
#include "ListNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {//O(1) space
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1){
            return head;
        }

        int len = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while(head != nullptr){
            ++len;
            head = head->next;
        }
        ListNode* prev_group_last = dummy;
        for(int i = 0; i+k-1 < len; i+=k){
            ListNode* first = prev_group_last;
            ListNode* second = first->next;
            ListNode* next = second->next;
            for(int j = 1; j <= k-1; ++j){
                first = second;
                second = next;
                if(next != nullptr){
                    next = next->next;
                }
                second->next = first;
            }
            ListNode* cur_group_last = prev_group_last->next;
            cur_group_last->next = next;
            prev_group_last->next = second;
            prev_group_last = cur_group_last;
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};

class Solution1 {//recursive
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool grouped = false;
        return KGroup(head, nullptr, nullptr, k, 1, grouped);
    }

    ListNode* KGroup(ListNode* pNode, ListNode* prev, ListNode* k_tail, const int k, int pos, bool& grouped){
        if(pNode == nullptr){
            return nullptr;
        }
        if(pos == 1){
            k_tail = pNode;
        }
        if(pos == k){
            grouped = true;
            bool next_K_grouped = false;
            auto next_head = KGroup(pNode->next, nullptr, nullptr, k, 1, next_K_grouped);
            pNode->next = prev;
            k_tail->next = next_head;
            return pNode;
        }else{
            auto new_head = KGroup(pNode->next, pNode, k_tail, k, pos+1, grouped);
            if(grouped){
                if(pos != 1){
                    pNode->next = prev;
                }
                return new_head;
            }else{
                return k_tail;
            }
        }
    }
};