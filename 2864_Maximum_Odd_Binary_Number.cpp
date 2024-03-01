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
    std::string maximumOddBinaryNumber(std::string s) 
    {
        int oneCount = -1;
        for(auto& c: s)
        {
            if(c == '1')
            {
                ++oneCount;
            }            
        }

        for(int i = 0; i < s.length()-1; ++i)
        {   
            if(oneCount > 0)
            {
                s[i] = '1';
                --oneCount;
            }
            else
            {
                s[i] = '0';
            }
        }
        s.back() = '1';
        return s;
    }
};