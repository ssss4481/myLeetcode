#include <vector>
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
    int maxProductDifference(std::vector<int>& nums) 
    {
        int min1 = INT32_MAX;
        int min2 = INT32_MAX;
        int max1 = INT32_MIN;
        int max2 = INT32_MIN;

        for(auto& n: nums)
        {
            if(n > max1)
            {
                max2 = max1;
                max1 = n;
            }
            else if(n > max2)
            {
                max2 = n;
            }

            if(n < min1)
            {
                min2 = min1;
                min1 = n;
            }
            else if(n < min2)
            {
                min2 = n;
            }
        }

        return (max1*max2) - (min1*min2);
    }
};

class Solution1 
{
public:
    int maxProductDifference(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        const int last = nums.size()-1;
        return (nums[last] * nums[last-1]) - (nums[1] * nums[0]);
    }
};