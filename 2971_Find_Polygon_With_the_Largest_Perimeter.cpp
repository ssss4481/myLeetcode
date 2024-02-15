#include <vector>
#include <numeric>
#include <algorithm>
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
    long long largestPerimeter(std::vector<int>& nums) 
    {
        std::sort(nums.rbegin(), nums.rend());

        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);

        for(int i = 0; i < nums.size()-2; ++i)
        {
            sum -= nums[i];         
            if(nums[i] < sum)
            {
                return sum+nums[i];
            }
        }

        return -1;        
    }
};