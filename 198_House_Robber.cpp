#include <vector>
#include <algorithm>
class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for(int i = 0; i < nums.size()-2; ++i){
            dp[i+2] = std::max(dp[i+2], dp[i]+nums[i+2]);
            if(i+3 < nums.size()){
                dp[i+3] = std::max(dp[i+3], dp[i]+nums[i+3]);
            }
        }
        return std::max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};