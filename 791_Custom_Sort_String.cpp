#include <unordered_map>
#include <string>
#include <algorithm>
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
    std::string customSortString(std::string order, std::string s) 
    {
        std::unordered_map<char, int> orderCount;

        for(auto& c: s)
        {
            ++orderCount[c];
        }

        int pi = 0;

        for(auto& c: order)
        {
            while(orderCount[c]-- > 0)
            {
                s[pi++] = c;
            }
            orderCount.erase(c);
        }        

        for(auto& p: orderCount)
        {
            while(p.second-- > 0)
            {
                s[pi++] = p.first;
            }
        }         

        return s;
    }
};

class Solution1 
{
public:
    std::string customSortString(std::string order, std::string s) 
    {
        std::unordered_map<char, int> orderMap;
        for(int i = 0; i < order.length(); ++i)
        {
            orderMap[order[i]] = i;
        }

        auto cmp = [&orderMap](const char& a, const char& b)
        {
            return orderMap[a] < orderMap[b];
        };
        
        std::sort(s.begin(), s.end(), cmp);

        return s;
    }
};