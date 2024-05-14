#include <vector>
#include <queue>
#include <algorithm>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> PQ;
        for(auto head: lists){
            while(head != nullptr){
                PQ.push_back(head);
                head = head->next;
            }
        }

        const int n = PQ.size();
        
        if(n == 0){
            return nullptr;
        }

        auto cmp = [](ListNode* node1, ListNode* node2){
            return node1->val < node2->val;
        };

        make_heap(PQ.begin(), PQ.end(), cmp);

        for(int i = 0; i < n-1; ++i){
            pop_heap(PQ.begin(), PQ.end()-i, cmp);
        }

        for(int i = 0; i < n-1; ++i){
            PQ[i]->next = PQ[i+1];
        }
        PQ.back()->next = nullptr;

        return PQ.front();
    }
};


typedef std::pair<int, ListNode*> IA;

class Solution1 
{
public:
    ListNode* Head;
    ListNode* LastNode;

    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        auto cmp = [](const IA& iva1, const IA& iva2)
        {
            return iva1.second->val > iva2.second->val;
        };

        this->Head = nullptr;
        std::priority_queue<IA, std::vector<IA>, decltype(cmp)> PQ(cmp);

        for(int i = 0; i < lists.size(); ++i)
        {
            if(lists[i] != nullptr)
            {
                PQ.push({i, lists[i]});
            }
        }

        while(PQ.size() > 1)
        {
            int i = PQ.top().first;
            lists[i] = lists[i]->next;
            this->insert(PQ.top().second);
            PQ.pop();

            if(lists[i] != nullptr)
            {
                PQ.push({i, lists[i]});
            }
        }

        if(PQ.size() == 1)
        {
            int i = PQ.top().first;
            this->insert(PQ.top().second);
        }

        return this->Head;    
    }

    void insert(ListNode* NextNode)
    {
        if(this->Head == nullptr)
        {
            this->Head = NextNode;
            this->LastNode = NextNode;
            return;
        }
        this->LastNode->next = NextNode;
        this->LastNode = NextNode;
    }
};
