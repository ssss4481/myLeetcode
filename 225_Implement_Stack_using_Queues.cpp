#include <queue>

class MyStack 
{
public:
    std::queue<int> Q1;

    MyStack() 
    {
        this->Q1 = std::queue<int>();
    }
    
    void push(int x) 
    {
        this->Q1.push(x);        
    }

    int pop() 
    {
        std::queue<int> Q;
        while (Q1.size() > 1)
        {
            Q.push(Q1.front());
            Q1.pop();
        }        
        this->Q1.swap(Q);
        return Q.front();
    }
    
    int top() 
    {
        return this->Q1.back();        
    }

    bool empty() 
    {
        return this->Q1.size() == 0;       
    }
};