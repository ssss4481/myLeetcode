#include <vector>
#include <unordered_map>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> intToCount;
        int ret = 0;
        int lo = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            ++intToCount[nums[i]];
            if(intToCount[nums[i]] > k)
            {
                ret = std::max(ret, i-lo);
                while(intToCount[nums[i]] > k)
                {
                    --intToCount[nums[lo++]];
                }
            }
        }
        ret = std::max(ret, int(nums.size())-lo);
        return ret;
    }
};