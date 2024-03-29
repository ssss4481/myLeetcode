#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();
//3. Longest Substring Without Repeating Characters
class Solution 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        const int len = s.length();
        bool record[256] = {false};
        int lo = 0;
        int ret = 0;
        for(int i = 0; i < len; ++i)
        {
            if(record[s[i]])
            {
                ret = std::max(ret, i-lo);
                while(s[lo] != s[i])
                {
                    record[s[lo++]] = false;
                }
                ++lo;
            }
            record[s[i]] = true;
        }
        ret = std::max(ret, len-lo);
        return ret;
    }
};




class Solution3 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::unordered_map<char, u_int32_t> charToIdx;

        u_int32_t                           start_idx {0};
        u_int32_t                           maxLength {0};

        for(u_int32_t i = 0; i < s.length(); ++i)
        {          
            if(charToIdx.count(s[i]) != 0 && charToIdx[s[i]] >= start_idx)
            {
                maxLength  = std::max(maxLength, i - start_idx);
                start_idx  = charToIdx[s[i]] + 1;
            }

            charToIdx[s[i]] = i;
        }

        maxLength = std::max(maxLength, u_int32_t(s.length())-start_idx);
        
        return int(maxLength);
    }
};



class Solution2 
{
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::unordered_map<char, u_int32_t> charToIdx;

        u_int32_t start_idx       {0};
        u_int32_t maxLength       {0};
        u_int32_t currentLength   {0};

        for(u_int32_t i = 0; i < s.length(); ++i)
        {          
            if(charToIdx.count(s[i]) != 0 && charToIdx[s[i]] >= start_idx)
            {
                maxLength       = std::max(maxLength, currentLength);
                currentLength   = i - charToIdx[s[i]] - 1;
                start_idx       = charToIdx[s[i]] + 1;
            }

            charToIdx[s[i]] = i;
            ++currentLength;
        }

        maxLength = std::max(maxLength, currentLength);

        return int(maxLength);
    }
};