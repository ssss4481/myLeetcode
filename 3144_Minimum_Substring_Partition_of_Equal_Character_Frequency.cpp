#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> dp(s.size()+1, -1);
        dp.back() = 0;
        return solve(s, 0, dp);
    }

    int solve(const string& s, int i, vector<int>& dp){
        if(dp[i] != -1){
            return dp[i];
        }
        dp[i] = s.length()-i;
        unordered_map<char, int> counts;
        for(int t = i; t < s.length(); ++t){    
            ++counts[s[t]];
            if(valid(counts)){
                dp[i] = min(dp[i], solve(s, t+1, dp)+1);
            }
        }
        return dp[i];
    }
    
    bool valid(unordered_map<char, int>& counts){
        int count = (*counts.begin()).second;
        for(auto& p: counts){
            if(p.second != count){
                return false;
            }
        }
        return true;
    }


};