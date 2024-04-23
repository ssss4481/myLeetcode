#include <vector>
#include <algorithm>
#include "ListNode.hpp"

class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head, nullptr);
    }

    ListNode* mergesort(ListNode* head, ListNode* tail){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        if(head->next->next == nullptr){
            auto next = head->next;
            if(head->val <= next->val){
                return head;
            }
            next->next = head;
            head->next = nullptr;
            return next;
        }

        ListNode* oneStep = head;
        ListNode* twoStep = head;
        while(twoStep != nullptr && twoStep->next != tail){
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        auto next_start = oneStep->next;
        oneStep->next = nullptr;
        auto left_part = mergesort(head, nullptr);
        auto right_part = mergesort(next_start, nullptr);
        return merge(left_part, right_part);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head = left->val <= right->val ? left : right;
        ListNode* tail = head;
        
        if(head == left){
            left = left->next;
        }else{
            right = right->next;
        }
        
        while(left != nullptr && right != nullptr){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if(left != nullptr){
            tail->next = left;
        }else if(right != nullptr){
            tail->next = right;
        }

        return head;
    }
};


class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }

        std::vector<ListNode*> nodes;

        while(head != nullptr){
            nodes.push_back(head);
            head = head->next;
        }

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val < b->val;
        };
        std::sort(nodes.begin(), nodes.end(), cmp);

        nodes.back()->next = nullptr;
        for(int i = 0; i < nodes.size()-1; ++i){
            nodes[i]->next = nodes[i+1];
        }
        return nodes.front();
    }
};