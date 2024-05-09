#include <vector>
#include <algorithm>
#include "ListNode.hpp"

using namespace std;

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> nodes;
        while(head != nullptr){
            nodes.push_back(head);
            head = head->next;
        }

        auto cmp = [](const ListNode* a, const ListNode* b){
            return a->val < b->val;
        };

        sort(nodes.begin(), nodes.end(), cmp);

        for(int i = 0; i < nodes.size()-1; ++i){
            nodes[i]->next = nodes[i+1];
        }
        nodes.back()->next = nullptr;
        return nodes.front();
    }
};