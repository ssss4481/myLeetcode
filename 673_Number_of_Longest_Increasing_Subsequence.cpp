#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(2, vector<int>(nums.size(), 1));//0:length 1:count
        

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = i-1; j >= 0; --j)
            {
                if(nums[j] < nums[i])
                {
                    if(dp[0][j] >= dp[0][i])
                    {
                        dp[0][i] = dp[0][j] + 1;
                        dp[1][i] = dp[1][j];                       
                    }
                    else if(dp[0][j] == dp[0][i] - 1)
                    {
                        dp[1][i] += dp[1][j];
                    }
                }             
            }
        }
        int maxLength = *max_element(dp[0].begin(), dp[0].end());

        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(dp[0][i] == maxLength)
            {
                ret += dp[1][i];
            }
        }

        return ret;        
    }
};