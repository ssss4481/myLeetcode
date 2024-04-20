#include <vector>
#include <algorithm>

class Solution {
public:
    long long minOperationsToMakeMedianK(std::vector<int>& nums, int k) {
        
        long long ret = 0;
        std::sort(nums.begin(), nums.end());

        if(nums[nums.size()/2] == k){
            return 0;
        }

        if(nums[nums.size()/2] < k){
            for(int i = nums.size()/2; i < nums.size() && nums[i] < k; ++i){
                ret += k - nums[i];
            }
        }else{
            for(int i = nums.size()/2; i >= 0 && nums[i] > k; --i){
                ret += nums[i] - k;
            }
        }
        return ret;
    }
};