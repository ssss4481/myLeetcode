#include <string>
#include <iostream>
#include <vector>

class Solution 
{
public:
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
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


