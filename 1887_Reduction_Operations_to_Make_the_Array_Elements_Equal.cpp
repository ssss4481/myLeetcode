#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int reductionOperations(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        const int last = nums.size()-1;
        int largestIdx = last;
        int shouldBeSmallerIdx = largestIdx-1;
        int operations = 0;
        while(shouldBeSmallerIdx >= 0)
        {
            if(nums[largestIdx] != nums[shouldBeSmallerIdx])
            {
                operations += (last - shouldBeSmallerIdx);
                largestIdx = shouldBeSmallerIdx;
            }
            --shouldBeSmallerIdx;
        }
        return operations;              
    }
};