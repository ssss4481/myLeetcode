#include <stack>

class MyQueue 
{
private:
    std::stack<int> s1;
    std::stack<int> s2;

public:
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        this->s1.push(x);        
    }
    
    int pop() 
    {
        if(this->s2.empty())
        {   
            while (!this->s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }                      
        }
        int ret = s2.top();
        s2.pop();

        return ret;      
    }
    
    int peek() 
    {
        if(this->s2.empty())
        {   
            while (!this->s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }                      
        }
        return s2.top();     
    }
    
    bool empty() 
    {
        return s1.empty() && s2.empty();        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */