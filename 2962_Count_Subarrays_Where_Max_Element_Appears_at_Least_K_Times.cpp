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
    long long countSubarrays(std::vector<int>& nums, int k)     
    {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        std::vector<int> maxValPosition;
        for(int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            if(nums[i] == maxVal)
            {
                maxValPosition.push_back(i);
            }
        }
        maxValPosition.push_back(static_cast<int>(nums.size()));
        if(static_cast<int>(maxValPosition.size()) < k+1)
        {
            return 0;
        }
        int lo = 0;
        int hi = lo + k - 1;
        long long count = 0;
        while(hi < maxValPosition.size()-1)
        {
            count += static_cast<long long>(maxValPosition[lo]+1)*static_cast<long long>(maxValPosition[hi+1]-maxValPosition[hi]);
            ++lo;
            ++hi;
        }
        return count;        
    }
};