#include <iostream>
#include <vector>
#include <algorithm>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int minPairSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        uint32_t lo = 0;
        uint32_t hi = nums.size()-1;
        int ret = -1;
        while(lo < hi)
        {
            ret = std::max(ret, nums[lo++]+nums[hi--]);            
        }

        return ret;        
    }
};