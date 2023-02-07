#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int lo = prices[0];
        int hi = prices[0];
        int maxDelta = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < lo)
            {
                maxDelta = max(hi-lo, maxDelta);
                lo = prices[i];
                hi = prices[i];
            }
            else if(prices[i] > hi)
            {
                hi = prices[i];
            }
        }
        return max(maxDelta, hi-lo);
    }
};