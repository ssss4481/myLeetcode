#include <vector>
#include <iostream>
#include <algorithm>

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
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed)
    {
        const int n = dist.size();
        auto calculateArriveTime = [&]()
        {
            for(int i = 0; i < n; ++i)
            {
                int oneMoreRound = (dist[i] % speed[i] != 0) ? 1 : 0;
                dist[i] = dist[i]/speed[i] + oneMoreRound + 1;               
            }
        };

        calculateArriveTime();
        std::sort(dist.begin(), dist.end());

        for(int t = 0; t < n; ++t)
        {
            if(dist[t] <= t)
            {
                return t-1;
            }
        }
        return n;        
    }
};

