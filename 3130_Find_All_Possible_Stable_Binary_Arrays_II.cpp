#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[zero+1][one+1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        for(int z = 0; z <= zero; ++z){
            for(int o = 0; o <= one; ++o){
                if(z == 0 && o == 0){
                    continue;
                }
                const int l1 = min(z, limit);
                for(int i = 1; i <= l1; ++i){
                    dp[z][o][1] += dp[z-i][o][0];
                    dp[z][o][1] %= MOD;
                }
                const int l2 = min(o, limit);
                for(int i = 1; i <= l2; ++i){
                    dp[z][o][0] += dp[z][o-i][1];
                    dp[z][o][0] %= MOD;
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1])%MOD;
    }
};



class Solution1 {//TLE
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero+1, vector<vector<long long>>(one+1, vector<long long>(2, -1)));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        return static_cast<int>((placeNumber(zero, one, limit, 0, dp) + placeNumber(zero, one, limit, 1, dp))%MOD);
    }
    int placeNumber(int zero, int one, const int limit, int prev, vector<vector<vector<long long>>>& dp){
        if(zero < 0 || one < 0){
            return 0;
        }

        if(dp[zero][one][prev] != -1){
            return dp[zero][one][prev];
        }

        dp[zero][one][prev] = 0;

        if(prev == 0){
            for(int i = 1; i <= limit; ++i){
                dp[zero][one][prev] += placeNumber(zero, one-i, limit, 1, dp);
            }
        }else{
            for(int i = 1; i <= limit; ++i){
                dp[zero][one][prev] += placeNumber(zero-i, one, limit, 0, dp);
            }
        }
        dp[zero][one][prev] %= MOD;
        return dp[zero][one][prev];
    }

};