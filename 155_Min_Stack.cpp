#include <stack>

class MinStack {
public:
    std::stack<int> st;
    std::stack<int> mins;

    MinStack() {
        
    }
    
    void push(int val) {
        this->st.push(val);
        if(this->mins.empty() || this->mins.top() > val){
            this->mins.push(val);
        }else{
            this->mins.push(this->mins.top());
        }
    }
    
    void pop() {
        this->st.pop();
        this->mins.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */