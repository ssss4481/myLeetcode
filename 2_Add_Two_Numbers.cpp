#include <iostream>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}Node;

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* pSumCurrent = nullptr;
        ListNode* pSumHead = nullptr;
        int v1 = 0;
        int v2 = 0;
        int carry = 0;
        while(ptr1 != nullptr || ptr2 != nullptr)
        {
            v1 = (ptr1 != nullptr ? ptr1->val : 0);
            v2 = (ptr2 != nullptr ? ptr2->val : 0);
            //std::cout << v1 << " " << v2 << " " << carry << "\n";
            ptr1 = (ptr1 != nullptr ? ptr1->next : nullptr);
            ptr2 = (ptr2 != nullptr ? ptr2->next : nullptr);
            int new_val = (v1 + v2 + carry) % 10;

            if(pSumHead == nullptr)
            {
                pSumHead = new ListNode(new_val);
                pSumCurrent = pSumHead;
            }
            else
            {
                pSumCurrent->next = new ListNode(new_val);
                pSumCurrent = pSumCurrent->next;
            }

            carry = (v1 + v2 + carry >= 10 ? 1 : 0);

            if((ptr1 == nullptr && ptr2 == nullptr) && carry == 1)
            {
                pSumCurrent->next = new ListNode(1);
                pSumCurrent = pSumCurrent->next;
            }
        }
        return pSumHead;
    }
};

void readNode(Node* pHead)
{
    Node* ptr = pHead;
    while(ptr != nullptr)
    {
        std::cout << ptr->val << "\n";
        ptr = ptr->next;
    }
    std::cout << "------\n";
}

void delList(Node* pHead)
{
    Node* ptr = pHead;
    while(ptr != nullptr)
    {
        ptr = ptr->next;
        delete pHead;
        pHead = ptr;
    }
    //std::cout << "------\n";
}


int main()
{
    Solution sol;
    int num = 0;
    Node* pHeadarr[2];
    Node* pHead = nullptr;
    for(int i = 0; i <= 1 ; ++i)
    {
        while(true)
        {
            std::cin >> num;
            Node* born;
            if(num == 10)
            {
                break;
            }
            born = new Node(num, pHead);
            pHead = born;
        }
        pHeadarr[i] = pHead;
        pHead = nullptr;
        //readNode(pHeadarr[i]);
    }
    //exit(0);
    //std::cout << "here 1\n";
    Node* rval = sol.addTwoNumbers(pHeadarr[0], pHeadarr[1]);
    readNode(rval);
    //std::cout << "here 2\n";
    for (int i = 0; i <= 1 ; ++i)
    {
        delList(pHeadarr[i]);
    }
    delList(rval);
    return 0;
}





