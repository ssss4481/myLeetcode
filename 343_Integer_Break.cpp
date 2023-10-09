#include <iostream>
#include <algorithm>
#include <vector>

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    int integerBreak(int n)     
    {
        std::vector<int> dp(n+1, 0);
        for(int i = 1; i < dp.size()-1; ++i)
        {
            for(int j = 1; j < i/2+1; ++j)
            {
                dp[i] = std::max(dp[i-j]*dp[j], dp[i]);
            }
            dp[i] = std::max(i, dp[i]);
        }
        for(int i = 1; i < n/2+1; ++i)
        {
            dp[n] = std::max(dp[n], dp[n-i]*dp[i]);
        }
        return dp[n];
    }
};





class Solution2//fail 
{
public:
    int pow(int base, int p)
    {
        if(base == 1)
        {
            return 1;
        }

        if(p == 0)
        {
            return 1;
        }
        if(p == 1)
        {
            return base;
        }

        if(p&1)
        {
            return base*pow(base*base, p/2);
        }
        else
        {
            return pow(base*base, p/2);
        }
    }

    int integerBreak(int n) 
    {
        int ret = 0;
        for(int base = 1; base <= n; ++base)//split n into k integers
        {
            int result;
            int r = n%base;
            int q = n/base;

            if(q + (r == 0 ? 0 : 1) < 2)
            {               
                break;
            }
            if(r)
            {
                result = r*pow(base, q);
            }
            else
            {
                result = pow(base, q);
            }
            ret = std::max(ret, result);
        }
        return ret;        
    }
};