#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int ret = 0;
        bool zeroExist = false;

        int containAtMostAZero = 0;
        int continuousOnes = 0;

        for(int&num : nums)
        {
            if(num == 0)
            {
                zeroExist = true;
                ret = max(ret, containAtMostAZero);
                containAtMostAZero = continuousOnes;
                continuousOnes = 0;
            }
            else
            {
                ++containAtMostAZero;
                ++continuousOnes;
            }
        }

        ret = max(ret, containAtMostAZero);
        
        if(!zeroExist)
        {
            --ret;
        }

        return ret;
    }
};



class Solution1
{
public:
    void printdp(vector<vector<int>>& dp, const int& n, int row)
    {
        for(int i = 0; i < n; ++i)        
        {
            cout << dp[row][i] << ' ';
        }
        cout << '\n';
    }

    int longestSubarray(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n, 0)); //dp[0] ignore 1 zero, dp[1] has not ignore any 0.

        int ret = 0;
        bool zeroExist = false;

        if(nums[0] == 1)
        {
            dp[0][0] = 1;
            dp[1][0] = 1;
            ret = 1;
        }
        else
        {
            zeroExist = true;
        }       

        for(int i = 1; i < n; ++i)
        {
            if(nums[i] == 1)
            {
                dp[0][i] = dp[0][i-1]+1;
                dp[1][i] = dp[1][i-1]+1;
            }
            else
            {
                dp[0][i] = dp[1][i-1];
                zeroExist = true;
            }
            ret = max(ret, dp[0][i]);
        }


        if(!zeroExist)
        {
            --ret;
        }

        return ret;
    }
};