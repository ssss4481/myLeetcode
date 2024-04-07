#include <string>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::string minRemoveToMakeValid(std::string& s) 
    {
        int left = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(')
            {
                ++left;
            }
            else if(s[i] == ')')
            {
                if(left == 0)
                {
                    s.erase(i, 1);
                    --i;
                }
                else
                {
                    --left;
                }
            }
        }

        if(left > 0)
        {
            for(int i = s.length()-1; left > 0; --i)
            {
                if(s[i] == '(')
                {
                    s.erase(i, 1);
                    --left;
                }
            }
        }
        return std::move(s);
    }
};