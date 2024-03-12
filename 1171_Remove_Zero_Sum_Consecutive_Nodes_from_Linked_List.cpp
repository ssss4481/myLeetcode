#include <unordered_map>
#include <vector>
#include <iostream>
#include "ListNode.hpp"


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


//https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/solutions/4862164/linked-list-prefix-sum-with-map-or-unordered-map-0ms-beats-100
class Solution 
{
public:    
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode node = ListNode(0, head);

        std::unordered_map<int, ListNode*> table;
        int prefix = 0;
        for(ListNode* pNode=&node; pNode != nullptr; pNode=pNode->next)
        {
            prefix += pNode->val;
            table[prefix] = pNode;
        }
        prefix = 0;
        for(ListNode* pNode=&node; pNode != nullptr; pNode=pNode->next)
        {
            prefix += pNode->val;
            pNode->next = table[prefix]->next;
        }
        return node.next;
    }
};