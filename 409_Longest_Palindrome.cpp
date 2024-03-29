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
    int longestPalindrome(std::string s) 
    {
        int count[256] = {0};
        
        for(auto&c : s)
        {
            ++count[c];
        }

        int len = 0;
        bool midSingle = false;
        for(char c = 'a'; c <= 'z'; ++c)
        {
            if(count[c] % 2 == 1)
            {
                midSingle = true;
                --count[c];
            }
            len += count[c];
        }
        for(char c = 'A'; c <= 'Z'; ++c)
        {
            if(count[c] % 2 == 1)
            {
                midSingle = true;
                --count[c];
            }
            len += count[c];
        }      

        if(midSingle) 
        {
            ++len;
        }

        return len;
    }
};