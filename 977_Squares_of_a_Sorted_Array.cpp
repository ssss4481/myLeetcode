#include <algorithm>
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
    std::vector<int> sortedSquares(std::vector<int>& nums) 
    {
        if(nums[0] >= 0)
        {
            for(auto& num: nums)
            {
                num *= num;
            }
            return nums;
        }

        int negativeIdx;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] >= 0)
            {
                break;
            }
            negativeIdx = i;
        }
        int positiveIdx = negativeIdx+1;
        int pos = 0;

        std::vector<int> ret(nums.size());

        while(positiveIdx < nums.size() && negativeIdx >= 0)
        {
            if(nums[positiveIdx] <= abs(nums[negativeIdx]))
            {
                ret[pos] = nums[positiveIdx]*nums[positiveIdx];
                ++positiveIdx;
            }
            else
            {
                ret[pos] = nums[negativeIdx]*nums[negativeIdx];
                --negativeIdx;
            }
            ++pos;           
        }

        while(positiveIdx < nums.size())
        {
            ret[pos] = nums[positiveIdx]*nums[positiveIdx];
            ++positiveIdx;
            ++pos;           
        }
        while(negativeIdx >= 0)
        {
            ret[pos] = nums[negativeIdx]*nums[negativeIdx];
            --negativeIdx;        
            ++pos;  
        }
        return ret;    
    }
};