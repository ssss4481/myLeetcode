#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        const int n = nums.size();
        bool dp[target+1];
        memset(dp, false, (target+1)*sizeof(bool));
        dp[0] = true;

        for(int& n : nums){
            for(int i = target; i >= 0; --i){
                if(i-n >= 0){
                    dp[i] = dp[i] | dp[i-n];
                }
            }
        }

        return dp[target];
    }
};