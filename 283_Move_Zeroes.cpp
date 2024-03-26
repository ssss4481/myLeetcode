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
    void moveZeroes(std::vector<int>& nums) 
    {
        int lo = 0;
        for(auto& n : nums)
        {
            if(n != 0)
            {
                std::swap(n, nums[lo++]);
            }
        }
    }
};