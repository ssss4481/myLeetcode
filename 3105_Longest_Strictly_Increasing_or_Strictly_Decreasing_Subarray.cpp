#include <vector>
#include <algorithm>

class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int len = 1;

        int inc_lo = 0;
        int inc_hi = 0;
        
        int dec_lo = 0;
        int dec_hi = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i-1]){
                ++inc_hi;
            }else{
                len = std::max(len, inc_hi-inc_lo+1);
                inc_lo = i;
                inc_hi = i;
            }

            if(nums[i] > nums[i-1]){
                ++dec_hi;
            }else{
                len = std::max(len, dec_hi-dec_lo+1);
                dec_lo = i;
                dec_hi = i;
            }

        }
        len = std::max(len, inc_hi-inc_lo+1);
        len = std::max(len, dec_hi-dec_lo+1);

        return len;
    }
};