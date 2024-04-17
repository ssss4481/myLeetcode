#include <string>
#include <iostream>
#include <vector>

class Solution{//O(1) space
public:
    bool backspaceCompare(std::string s, std::string t) {

        auto fixString = [](std::string& str){
            for(int i = 0; i < str.size(); ++i){
                if(str[i] == '#'){
                    if(i > 0){
                        str.erase(i-1, 2);
                        i-=2;
                    }
                    else{
                        str.erase(i, 1);
                        --i;
                    }
                }
            }
        };

        fixString(s);
        fixString(t);
        return s == t;
    }
};


class Solution1
{
public:
    bool backspaceCompare(std::string s, std::string t) 
    {
        std::vector<char> s_stack;
        std::vector<char> t_stack;

        auto build_stack = [](std::string& str, std::vector<char>& stk)mutable
        {
            for(auto& c: str)
            {
                if(c == '#')
                {
                    if(!stk.empty())
                    {
                        stk.pop_back();
                    }
                }
                else
                {
                    stk.push_back(c);
                }
            }
        };
        build_stack(s, s_stack);
        build_stack(t, t_stack);
        return s_stack == t_stack;        
    }
};


