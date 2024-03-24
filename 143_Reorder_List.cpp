#include <vector>
#include "ListNode.hpp"

class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        std::vector<ListNode*> pNodes;
        ListNode* pNode = head;
        while(pNode != nullptr)
        {
            pNodes.push_back(pNode);
            pNode = pNode->next;
        }

        int lo = 0;
        int hi = pNodes.size()-1;
        const int hiStart = hi;
        

        if(hiStart <= 1)
        {
            return;
        }


        bool step = true;

        while (lo < hi)
        {
            pNodes[lo]->next = pNodes[hi];
            pNodes[hi]->next = pNodes[lo+1];
            ++lo;
            --hi;
        }
        if(hiStart % 2 == 0)
        {
            pNodes[hi+1]->next = pNodes[lo];
            pNodes[lo]->next = nullptr;            
        }
        else
        {
            pNodes[hi+1]->next = nullptr;
        }

    }
};