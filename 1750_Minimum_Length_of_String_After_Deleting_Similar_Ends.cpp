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
    int minimumLength(std::string s) 
    {
        int lo = 0;
        int hi = s.length()-1;
        while(s[lo] == s[hi] && lo < hi)
        {
            char c = s[lo];
            while(lo < hi && s[lo] == c)
            {
                ++lo;
            }
            while(s[hi] == c)
            {
                if(lo == hi)
                {
                    return 0;
                }
                --hi;                
            }            
        }
        return hi-lo+1;
    }
};

