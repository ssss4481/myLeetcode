#include<vector>
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
    std::vector<int> findAnagrams(std::string s, std::string p) 
    {
        if(s.length() < p.length())
        {
            return {};
        }

        std::vector<int> pCount(26, 0);
        std::vector<int> allZero(26, 0);
        
        for(auto& c: p)
        {
            ++pCount[static_cast<uint32_t>(c-'a')];
        }

        for(int i = 0; i < p.length(); ++i)
        {
            --pCount[static_cast<uint32_t>(s[i]-'a')];
        }

        std::vector<int> ret;
        int lo = 0;
        int hi = lo+p.length();

        while (hi < s.length())
        {
            if(pCount == allZero)
            {
                ret.push_back(lo);
            }
            ++pCount[static_cast<uint32_t>(s[lo++]-'a')];
            --pCount[static_cast<uint32_t>(s[hi++]-'a')];
        }
        if(pCount == allZero)
        {
            ret.push_back(lo);
        }

        return ret;
    }
};
