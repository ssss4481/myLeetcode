#include <vector>
#include <numeric>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minimumOperations(std::vector<std::vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        std::vector<std::vector<int>> cost(n, std::vector<int>(10, m));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                --cost[j][grid[i][j]];
            }
        }

        std::vector<std::vector<int>> dp(n, std::vector<int>(10, INT_MAX));
        dp[0] = cost[0];

        for(int j = 1; j < n; ++j){
            for(int current = 0; current <= 9; ++current){
                for(int prev = 0; prev <= 9; ++prev){
                    if(current == prev){
                        continue;
                    }
                    dp[j][current] = std::min(dp[j][current], cost[j][current]+dp[j-1][prev]);
                }
            }
        }

        return *(std::min_element(dp.back().begin(), dp.back().end()));
    }
};