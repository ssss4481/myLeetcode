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
    int threeSumClosest(std::vector<int>& nums, int target) 
    {
        int ret = 0;
        int bestDiff = INT_MAX;

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size()-2; ++i)
        {
            int j = i+1;
            int k = nums.size()-1;

            int subTarget = target-nums[i];

            int subSum = nums[j] + nums[k];
            int currentDiff = subSum-subTarget;
            do
            {
                if(abs(currentDiff) < abs(bestDiff))
                {
                    if(currentDiff == 0)
                    {
                        return target;
                    }
                    ret = subSum + nums[i];
                    bestDiff = currentDiff;
                }

                if(currentDiff > 0)
                {
                    --k;
                }
                else
                {
                    ++j;
                }
                subSum = nums[j] + nums[k];
                currentDiff = subSum-subTarget;
            }while (j < k);
        }
        return ret;
    }
};