#include <stack>
#include "ListNode.hpp"


class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        std::stack<int> s1 = valStack(l1);
        int carry = 0;
        combineStackToList(s1, l2, carry);
        appendRemainingStackToList(s1, l2, carry);
        return l2; 
    }

    std::stack<int> valStack(ListNode* l)    
    {
        std::stack<int> ret;
        while(l != nullptr)
        {   
            ret.push(l->val);
            l = l->next;
        }
        return ret;
    }

    void combineStackToList(std::stack<int>& s, ListNode*& l, int& carry)
    {
        if(l->next != nullptr)
        {
            combineStackToList(s, l->next, carry);
        }

        int sum;

        if(s.empty())
        {
            sum = l->val + carry;            
        }
        else
        {
            sum = l->val + s.top() + carry;
            s.pop();
        }

        if(sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        l->val = sum;
    }  
    
    void appendRemainingStackToList(std::stack<int>& s, ListNode*& l, int& carry)
    {
        while(!s.empty())
        {
            int sum = s.top() + carry;

            if(sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s.pop();

            l = new ListNode(sum, l);
        }

        if(carry != 0)
        {
            l = new ListNode(1, l);
        }

    }

};





class Solution2
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        std::stack<int> s1 = valStack(l1);
        std::stack<int> s2 = valStack(l2);
        return sumTwoList(s1, s2);           
    }

    std::stack<int> valStack(ListNode*& l)    
    {
        std::stack<int> ret;
        while(l != nullptr)
        {   
            ret.push(l->val);
            l = l->next;
        }
        return ret;
    }

    ListNode* sumTwoList(std::stack<int>& s1, std::stack<int>& s2)     
    {
        int carry = 0;
        ListNode* head = new ListNode(-1);        
        while(!s1.empty() && !s2.empty())
        {            
            int sum = s1.top() + s2.top() + carry;
            if(sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            head->val = sum;
            ListNode* temp = new ListNode(-1);            
            temp->next = head;
            head = temp;

            s1.pop();
            s2.pop();
        }

        if(carry == 0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;            
            simplyAppend(head, s1);
            simplyAppend(head, s2);
        }
        else if(carry == 1 && s1.empty() && s2.empty())
        {
            head->val = 1;
        }
        else
        {
            carryAppend(head, s1);
            carryAppend(head, s2);
        }

        if(head->val == -1)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }        

        return head;
    }

    void simplyAppend(ListNode*& head, std::stack<int>& s)//no need to concern about carry.
    {
        if(s.empty())
        {
            return;
        }       


        while(!s.empty())
        {
            ListNode* temp = new ListNode(s.top());
            temp->next = head;            
            head = temp;
            s.pop();
        }
    }

    void carryAppend(ListNode*& head, std::stack<int>& s)
    {
        if(s.empty())
        {
            return;
        }

        int carry = 1;

        while(!s.empty())
        {
            int sum = s.top() + carry;
            if(sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            head->val = sum;
            ListNode* temp = new ListNode(0 + carry);            
            temp->next = head;
            head = temp;
            s.pop();
        }

        if(head->val <= 0)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

    }
};