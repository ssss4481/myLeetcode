#include <vector>
#include <string>
#include <stack>
#include <iostream>

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
    int evalRPN(vector<string>& tokens) {
        stack<int> num_st;

        auto isOperator = [](const string& token){
            return token == "+" || token == "-" || token == "*" || token == "/";
        };

        for(auto& token: tokens){
            int new_num;
            if(isOperator(token)){
                int b = num_st.top();
                num_st.pop();
                int a = num_st.top();
                num_st.pop();
                if(token == "+"){
                    new_num = a+b;
                }else if(token == "-"){
                    new_num = a-b;
                }else if(token == "*"){
                    new_num = a*b;
                }else if(token == "/"){
                    new_num = a/b;
                }
            }else{
                new_num = stoi(token);
            }
            num_st.push(new_num);
        }

        return num_st.top();        
    }
};


class Solution
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int> s;

        for(auto& token: tokens)
        {
            if(this->isOperator(token))
            {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(this->calculate(num1, num2, token));
            }
            else
            {
                s.push(atoi(token.c_str()));
            }
        }
        return s.top();        
    }

    bool isOperator(std::string& token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int calculate(int& num1, int& num2, std::string& op)
    {  
        if(op == "+")
        {
            return num1 + num2;
        }

        if(op == "-")
        {
            return num1 - num2;
        }
   
        if(op == "*")
        {
            return num1 * num2;
        }
   
        if(op == "/")
        {
            return num1 / num2;
        }

        return -1;
    }

};

class Solution2 
{
public:
    int evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<std::string> s;

        for(auto& token: tokens)
        {
            if(this->isOperator(token))
            {
                std::string num2 = s.top();
                s.pop();
                std::string num1 = s.top();
                s.pop();
                s.push(this->calculate(num1, num2, token));
            }
            else
            {
                s.push(token);
            }
        }
        return atoi(s.top().c_str());        
    }

    bool isOperator(std::string& token)
    {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    std::string calculate(std::string& num1, std::string& num2, std::string& op)
    {
        if(op == "+")
        {
            return std::to_string(atoi(num1.c_str()) + atoi(num2.c_str()));
        }
        if(op == "-")
        {
            return std::to_string(atoi(num1.c_str()) - atoi(num2.c_str()));
        }
        if(op == "*")
        {
            return std::to_string(atoi(num1.c_str()) * atoi(num2.c_str()));
        }        
        if(op == "/")
        {
            return std::to_string(atoi(num1.c_str()) / atoi(num2.c_str()));
        }        
        return "error";
    }

};