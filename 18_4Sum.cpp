#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> res_set;
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size(); ++j){
                if(j > i+2 && nums[j] == nums[j-1]){
                    continue;
                }
                int lo = j+1;
                int hi = nums.size()-1;
                while(lo < hi){
                    long long sum = static_cast<long long>(nums[lo])+nums[hi]+nums[i]+nums[j];
                    if(sum == target){
                        res_set.insert({nums[i], nums[j], nums[lo], nums[hi]});
                        ++lo;
                    }else if(sum < target){
                        ++lo;
                    }else{
                        --hi;
                    }
                }
            }
        }

        return std::vector<std::vector<int>>(res_set.begin(), res_set.end());
    }
};