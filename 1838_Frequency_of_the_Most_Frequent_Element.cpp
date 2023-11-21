#include <vector>
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
    int maxFrequency(std::vector<int>& nums, int k)     
    {
        std::sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = 1;
        long long int operations = 0;
        while(hi < nums.size())
        {
            operations += static_cast<long long int>(nums[hi] - nums[hi-1]) * (hi - lo);
            if(operations > k)
            {
                operations -= (nums[hi]-nums[lo++]);
            }
            ++hi;
        }
        return hi - lo;     
    }
};