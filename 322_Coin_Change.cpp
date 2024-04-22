#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i = 0; i <= amount; ++i){
            for(auto& coin: coins){
                if(coin <= i){
                    dp[i] = std::min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] <= amount ? dp[amount] : -1;
    }

};