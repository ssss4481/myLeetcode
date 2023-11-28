#include <vector>
#include <numeric>

#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) 
    {
        const int n = nums.size();
        std::vector<int> result(n);
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int base = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > base)
            {
                sum -= (nums[i]-base)*(n-i-i);
                base = nums[i];
                result[i] = sum;
            }
            else
            {                
                result[i] = result[i-1];
            }
        }
        return result;        
    }
};