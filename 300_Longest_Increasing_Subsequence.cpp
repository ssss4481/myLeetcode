#include <vector>
#include <algorithm>


class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> pseudo_LIS;

        int longest_len = 1;
        pseudo_LIS.push_back(nums[0]);

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > pseudo_LIS.front() && nums[i] < pseudo_LIS.back()){
                auto it = std::lower_bound(pseudo_LIS.begin(), pseudo_LIS.end(), nums[i]);
                if(*it != nums[i]){
                    *it = nums[i];
                }
            }else if(nums[i] > pseudo_LIS.back()){
                pseudo_LIS.push_back(nums[i]);
            }else if(nums[i] < pseudo_LIS.front()){
                pseudo_LIS.front() = nums[i];
            }
            longest_len = std::max(longest_len, static_cast<int>(pseudo_LIS.size()));
        }

        return longest_len;
    }
};


class Solution1 {//dp
public:
    
    int lengthOfLIS(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> dp(n, 1);
        dp[n-1] = 1;
        int res = 0;
        for(int i = n-1; i >= 0; --i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] < nums[j]){
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            res = std::max(res, dp[i]);
        }
        return res;
    }
};