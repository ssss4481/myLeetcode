#include <iostream>
#include <vector>
#include <algorithm>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_and_val = nums[0];
        int lo = 0;
        int max_len = 1;
        int pre = nums[0];

        for(int hi = 1; hi < nums.size(); ++hi){
            int cur = pre & nums[hi];

            if(nums[hi] > cur){
                cur = nums[hi];
                lo = hi;
            }     
                  
            if(cur > max_and_val){
                max_and_val = cur;
                max_len = hi - lo + 1;
            }else if(cur == max_and_val){
                max_len = max(max_len, hi - lo + 1);
            }
            
            pre = cur;
        }
        return max_len;
    }
};