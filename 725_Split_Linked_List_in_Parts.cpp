#include <vector>
#include <iostream>
#include "ListNode.hpp"

using namespace std;

class Solution 
{

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> allNode;
        auto pCurrent = head;
        while(pCurrent != nullptr)
        {
            allNode.push_back(pCurrent);
            pCurrent = pCurrent->next;
        }
        vector<ListNode*> ret;
        const int n = allNode.size();

        if(k >= n)
        {
            for(auto pNode:allNode)
            {                
                pNode->next = nullptr;
                ret.push_back(pNode);
            }

            for(int i = 1; i <= k-n; ++i)
            {
                ret.push_back(nullptr);
            }
        }
        else //n > k
        {
            int q = n / k;
            int r = n % k;
            for(int i = 0; i < n; ++i)
            {
                ret.push_back(allNode[i]);
                i += (q-1);
                if(r > 0)
                {
                    --r;
                    ++i;
                }
                allNode[i]->next = nullptr;
            }
        }
        return ret;       
    }
};