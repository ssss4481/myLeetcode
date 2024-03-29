#include <vector>
#include <string>


class Solution 
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        int lo = 0;
        bool stop = false;
        while(!stop)
        {
            char c = strs[0][lo];
            for(auto& s: strs)
            {
                if(lo >= s.length() || s[lo] != c)
                {
                    stop = true;
                    break;
                }
            }
            ++lo;
        }

        return strs[0].substr(0, lo);
    }
};