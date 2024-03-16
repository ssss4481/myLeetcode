#include <vector>
#include <unordered_map>
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
    int findMaxLength(std::vector<int>& nums) 
    {
        std::unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int sum = 0;
        int maxLength = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
            {
                --sum;
            }
            else
            {
                ++sum;
            }

            
            if(hashMap.count(sum) == 1)
            {
                maxLength = std::max(maxLength, i - hashMap[sum]);
            }
            else
            {
                hashMap[sum] = i;
            }
        }
        return maxLength;
    }
};



class Solution2
{
public:
    int findMaxLength(std::vector<int>& nums) 
    {
        for(int i = 1; i < nums.size(); ++i)
        {
            
            nums[i] += nums[i-1];

        }
        int j;
        if(nums.size() % 2 == 1)
        {
            j = nums.size()-1;
        }
        else
        {
            j = nums.size();
        }

        for(; j > 0; j -= 2)
        {            
            int halfSize = j/2;
            for(int i = 0; i+j-1 < nums.size(); ++i)
            {
                int prefixSum = (i > 0) ? nums[i-1] : 0;
                if(nums[i+j-1]-prefixSum == halfSize)
                {
                    return halfSize*2;
                }
            }
        }
        return 0;
    }
};