#include <deque>
#include <iostream>
#include "ListNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        deque<ListNode*> dq;
        auto cur = head;
        while(cur != nullptr){
            while(!dq.empty() && cur->val > dq.back()->val){
                dq.pop_back();
            }
            dq.push_back(cur);
            cur = cur->next;
        }
        head = dq.front();
        cur = head;
        dq.pop_front();
        while(!dq.empty()){
            cur->next = dq.front();
            cur = cur->next;
            dq.pop_front();
        }
        return head;
    }
};