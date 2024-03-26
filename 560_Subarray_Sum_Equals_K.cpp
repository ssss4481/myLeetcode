#include <vector>
#include <unordered_map>
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
    int subarraySum(std::vector<int>& nums, int k) 
    {
        const int size = nums.size();
        for(int i = 1; i < size; ++i)
        {
            nums[i] += nums[i-1];
        }
        std::unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int count = 0;
        for(auto& sum: nums)
        {
            count += hashMap[sum-k];
            ++hashMap[sum];
        }
        return count;
    }
};


class Solution1//O(n^2)
{
public:
    int subarraySum(std::vector<int>& nums, int k) 
    {
        const int size = nums.size();
        std::vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i = 1; i < size; ++i)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        int count = 0;

        for(int i = 0; i < size; ++i)
        {
            int sum = prefixSum[i];
            for(int j = 0; j <= i; ++j)
            {
                if(sum == k)
                {
                    ++count;
                }
                sum = prefixSum[i] - prefixSum[j];
            }
        }
        return count;
    }
};