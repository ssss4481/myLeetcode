#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution 
{
public:
    int characterReplacement(std::string s, int k) 
    {
        int counts[26] = {0};

        int lo = 0;
        int hi = 0;
        int maxFidx = 0;
        int ret = 0;
    
        while(hi < s.length())
        {
            ++counts[s[hi]-'A'];
            maxFidx = counts[s[hi]-'A'] > counts[maxFidx] ? s[hi]-'A' : maxFidx;
            ++hi;
            if(hi-lo-counts[maxFidx] > k)
            {
                --counts[s[lo++]-'A'];
            }
            else
            {
                ret = std::max(ret, hi-lo);
            }
        }
        return ret;
    }
};