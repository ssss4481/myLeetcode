#include <vector>
#include <iostream>


#define _a_ 0
#define _e_ 1
#define _i_ 2
#define _o_ 3
#define _u_ 4

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    return 0;
}();

class Solution//correct 
{
public:
    int countVowelPermutation(int n) 
    {
        std::vector<int> dp1(5, 1);
        std::vector<int> dp2(5, 0);
        int mod = 1000000007;
        for(int i = 1; i < n; ++i)
        {
            dp2[_a_] = (dp1[_e_] + dp1[_i_] + dp1[_u_])%mod;
            dp2[_e_] = (dp1[_a_] + dp1[_i_])%mod;
            dp2[_i_] = (dp1[_e_] + dp1[_o_])%mod;
            dp2[_o_] = (dp1[_i_])%mod;
            dp2[_u_] = (dp1[_i_] + dp1[_o_])%mod;

            dp1.swap(dp2);
        }  
        int ret = 0;
        for(auto& n:dp1)
        {
            ret += n;
            ret %= mod;           
        }        
        return int(ret);
    }
};


class Solution2//correct 
{
public:
    std::vector<std::vector<int>> dp;

    int countVowelPermutation(int n) 
    {
        this->dp = std::vector<std::vector<int>> (5, std::vector<int>(n, 0));
        for(int i = 0; i < 5; ++i)
        {
            this->dp[i][0] = 1;
        }
        long long int ret = recursivePermutation(_a_, n-1) + recursivePermutation(_e_, n-1)
        + recursivePermutation(_i_, n-1) + recursivePermutation(_o_, n-1) + recursivePermutation(_u_, n-1);
        return ret % 1000000007;        
    }

    int recursivePermutation(int v, int remainingLength)
    {
        if(this->dp[v][remainingLength] != 0)
        {
            return this->dp[v][remainingLength];
        }
        int ret;
        switch (v)
        {
            case _a_:
                ret = this->recursivePermutation(_e_, remainingLength-1);
                break;
            case _e_:
                ret = this->recursivePermutation(_a_, remainingLength-1) + this->recursivePermutation(_i_, remainingLength-1);
                break;
            case _i_:
                ret = this->recursivePermutation(_a_, remainingLength-1) + this->recursivePermutation(_e_, remainingLength-1) 
                + this->recursivePermutation(_o_, remainingLength-1) + this->recursivePermutation(_u_, remainingLength-1);
                break;
            case _o_:
                ret = this->recursivePermutation(_i_, remainingLength-1) + this->recursivePermutation(_u_, remainingLength-1);
                break;
            case _u_:
                ret = this->recursivePermutation(_a_, remainingLength-1);
                break;            
            default:
                break;
        }
        this->dp[v][remainingLength] = ret % 1000000007;
        return this->dp[v][remainingLength];
    }

};