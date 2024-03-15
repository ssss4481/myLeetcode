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
    std::vector<int> productExceptSelf(std::vector<int>& nums) 
    {
        std::vector<int> result(nums.size());
        int product = 1;
        for(int i = 0; i < nums.size(); ++i)
        {
            result[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            result[i] *= product;
            product *= nums[i];
        }
        return result;  
    }
};