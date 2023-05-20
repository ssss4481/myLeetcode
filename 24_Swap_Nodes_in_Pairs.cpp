#include <iostream>
#include "ListNode.hpp"
using namespace std;

class Solution 
{
public:
    void swap(ListNode* first, ListNode* second)
    {
        ListNode* temp = second->next;        
        second->next = first;
        first->next = temp;

        //cout << first->val << " " << second->val << " " << first->next->val << " " << second->next->val <<"\n";
    }


    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* fakeNode = new ListNode(0, head);
        ListNode* tailOfPreviousPair = fakeNode;
        ListNode* first = nullptr;
        ListNode* second = nullptr;     
        while(current != nullptr)
        {
            //cout << current->val << "\n";
            first = current;
            second = current->next;
            if(second == nullptr)
                break;
            //cout<< first->val << second->val;
            //exit(0);
            if(first != nullptr && second != nullptr)
            {
                this->swap(first, second);
                //cout << first->val << " " << second->val << " " << first->next->val << " " << second->next->val <<"\n";
                tailOfPreviousPair->next = second;                
                if(tailOfPreviousPair == fakeNode)
                    head = second;
                tailOfPreviousPair = first;
                current = tailOfPreviousPair->next;
                first = nullptr;
                second = nullptr;
            }
        }
        delete fakeNode;
        return head;        
    }
};

void trace(ListNode* Node)
{
    while(Node != nullptr)
    {
        cout << Node->val << "\n";
        Node = Node->next;
    }
}


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    trace(head);

    Solution sol = Solution();
    head = sol.swapPairs(head);
    cout << "---\n";

    trace(head);


    return 0;
}