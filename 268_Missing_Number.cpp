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
    int missingNumber(std::vector<int>& nums) 
    {
        int sum = ((1+nums.size())*nums.size())/2;

        for(auto& n : nums)
        {
            sum -= n;
        }
        return sum;        
    }
};



class Solution1
{
public:
    int missingNumber(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return static_cast<int>(nums.size());        
    }
};



class Solution2
{
public:
    int missingNumber(std::vector<int>& nums) 
    {
        std::vector<bool> table(nums.size()+1, false);
        for(auto& n : nums)
        {
            table[n] = true;
        }

        for(int i = 0; i < nums.size()+1; ++i)
        {
            if(!table[i])
            {
                return i;
            }
        }

        return -1;        
    }
};