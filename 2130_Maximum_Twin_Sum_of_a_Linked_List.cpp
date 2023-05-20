#include <climits>
#include <iostream>
#include "ListNode.hpp"

using namespace std;


class Solution 
{
private:
    int maximum;
    ListNode* front;
    bool end;

public:
    void update(ListNode* current)
    {
        if(current->next != nullptr)
        {
            update(current->next);
        }
        if(!this->end)
        {
            if(front->val + current->val > this->maximum)
                this->maximum = front->val + current->val;
            if(front->next == current)
                this->end = true;
            this->front = front->next;               
        }   
    }

    int pairSum(ListNode* head) 
    {    
        this->maximum = INT_MIN;
        this->front = head;     
        this->end = false;   
        update(head);
        return this->maximum;
    }
};


int main(int argc, char const *argv[])
{
    return 0;
}


