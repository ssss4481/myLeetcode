#include <vector>
#include <cstring>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        const int n = prices.size();

        int buy[n];
        int cool[n];
        int sell[n];
        memset(buy, 0, sizeof(buy));
        memset(cool, 0, sizeof(cool));
        memset(sell, 0, sizeof(sell));

        buy[0] = -prices[0];

        for(int i = 1; i < n; ++i){
            buy[i] = std::max(cool[i-1]-prices[i], buy[i-1]);
            cool[i] = std::max(sell[i-1], cool[i-1]);
            sell[i] = buy[i-1]+prices[i];
        }

        return std::max({buy[n-1], cool[n-1], sell[n-1]});
    }
};