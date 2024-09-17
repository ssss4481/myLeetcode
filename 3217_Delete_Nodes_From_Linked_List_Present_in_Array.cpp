#include <iostream>
#include <vector>
#include <unordered_set>

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        auto prev = dummy;
        auto current = head;

        unordered_set<int> del_vals(nums.begin(), nums.end());

        while(current != nullptr){
            if(del_vals.count(current->val) == 1){
                auto del_node = current;
                current = current->next;
                prev->next = current;
                delete del_node;
            }else{
                prev = current;
                current = current->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};