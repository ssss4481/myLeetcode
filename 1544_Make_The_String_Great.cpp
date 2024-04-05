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
    std::string makeGood(std::string s) 
    {
        const int diff = abs('A'-'a');
        for(int i = 1; i < s.length(); ++i)
        {
            if(abs(s[i]-s[i-1]) == diff)
            {
                s.erase(i-1, 2);
                if(i > 1)
                {
                    i -= 2;
                }
                else
                {
                    --i;
                }
            }
        }
        return s;
    }
};