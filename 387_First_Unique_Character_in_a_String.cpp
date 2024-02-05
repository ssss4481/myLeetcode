#include <string>
#include <vector>
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
    int firstUniqChar(std::string s) 
    {
        std::vector<std::pair<int, int>> posAndCount(26, {-1, 0});
        for(int i = 0; i < s.length(); ++i)
        {
            auto& p = posAndCount[s[i]-'a'];
            if(p.first == -1)
            {
                p.first = i;
            }
            ++p.second;
        }

        auto cmp = [](std::pair<int, int>& a, std::pair<int, int>& b)
        {
            if(a.second == b.second)
            {
                return a.first < b.first;
            }
            return a.second < b.second;
        };

        std::sort(posAndCount.begin(), posAndCount.end(), cmp);

        for(auto& p: posAndCount)
        {
            if(p.second == 1)
            {
                return p.first;
            }
        }

        return -1;       
    }
};