#include <vector>
#include <iostream>
#include <algorithm>
#include "Matrix.hpp"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        vector< vector < vector<int> > > dp (prices.size()+1, vector< vector<int> > (2, vector<int> (k+1, 0)));
        //initialize
        for(int day = prices.size()-1; day >=0 ; --day)
        {
            for(int tranc = 1; tranc <= k ; ++tranc)
            {
                dp[day][0][tranc] = max(dp[day+1][0][tranc], dp[day+1][1][tranc] - prices[day]); //[x][0][y] means could buy
                dp[day][1][tranc] = max(dp[day+1][1][tranc], dp[day+1][0][tranc-1] + prices[day]);
            }
        }
        return dp[0][0][k];
    }
};

int main()
{
    return 0;
}