#include <vector>

class Solution {
public:
    long long countAlternatingSubarrays(std::vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }

        long long lo = 0;
        long long hi = 1;
        long long ret = 0;

        for(; hi < nums.size(); ++hi){
            if(nums[hi-1] == nums[hi]){
                ret += (1+hi-lo)*(hi-lo)/2;
                lo = hi;
            }
        }
        if(hi - 1 != lo){
            ret += (1+hi-lo)*(hi-lo)/2;
        }else{
            ++ret;
        }

        return ret;
    }
};