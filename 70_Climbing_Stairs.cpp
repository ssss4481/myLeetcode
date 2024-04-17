#include <vector>


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }

        int f1 = 1;
        int f2 = 2;

        for(int i = 3; i <= n; ++i){
            int temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        return f2;
        
    }
};


class Solution 
{
public:
    int climbStairs(int n) 
    {
        std::vector<int> dp(n+2, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];        
    }
};