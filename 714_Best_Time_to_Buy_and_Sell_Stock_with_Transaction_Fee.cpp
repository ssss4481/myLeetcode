#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee)     
    {
        const int n = prices.size();

        int hold = -prices[0];
        int free = 0;
        for(int i = 1; i < n; ++i)
        {
            hold = max(free - prices[i], hold);
            free = max(hold+prices[i]-fee, free);          
        }

        return free;  
    }
};


class Solution1 
{
public:
    int maxProfit(vector<int>& prices, int fee)     
    {
        const int n = prices.size();

        vector<int> hold(n, 0);
        vector<int> free(n, 0);

        hold[0] = -prices[0];

        for(int i = 1; i < n; ++i)
        {
            hold[i] = max(free[i-1] - prices[i], hold[i-1]);
            free[i] = max(hold[i-1]+prices[i]-fee, free[i-1]);          
        }

        return free[n-1];  
    }
};