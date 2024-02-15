#include <string>
#include <vector>
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
    std::string firstPalindrome(std::vector<std::string>& words)     
    {
        auto isPalindrome = [](std::string& s)
        {
            int lo = 0;
            int hi = s.length()-1;
            while (lo < hi)
            {
                if(s[lo++] != s[hi--])
                {
                    return false;
                }
            }
            return true;         
        };

        for(auto& word: words)
        {
            if(isPalindrome(word))
            {
                return word;
            }
        }    
        return "";
    }
};