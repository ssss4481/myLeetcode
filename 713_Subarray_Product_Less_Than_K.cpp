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
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) 
    {
        if(k <= 1)
        {
            return 0;
        }

        int lo = 0;
        long long int product = 1;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            product *= nums[i];
            while(product >= k)
            {
                if(nums[i] >= k)
                {
                    product = 1;
                    lo = i+1;
                    break;                    
                }
                product /= nums[lo++];
            }
            count += i - lo + 1;
        }

        return count;
    }
};