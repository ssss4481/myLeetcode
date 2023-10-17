#include <vector>
#include <algorithm>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int minCostClimbingStairs(std::vector<int>& cost) 
    {
        const int n = cost.size();
        std::vector<int> dp(n+1, 0);
        for(int i = 2; i < n+1; ++i)
        {
            dp[i] = std::min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        }       
        return dp[n];
    }
};