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
    int firstMissingPositive(std::vector<int>& nums) 
    {
        const int size = nums.size();

        for(int i = 0; i < size; ++i)
        {
            int x = nums[i];
            while(x >= 1 && x < size && x-1 != i && nums[x-1] != x)
            {
                std::swap(nums[x-1], nums[i]);
                x  = nums[i];
            }
        }
        
    
        for(int i = 0; i < size; ++i)
        {
            if(i+1 != nums[i])
            {
                return i+1;
            }
        }

        return size+1;
    }
};

class Solution1 
{
public:
    int firstMissingPositive(std::vector<int>& nums) 
    {
        std::vector<bool> hashTable(100001, false);
        for(auto&n : nums)
        {  
            if(n > 0 && n < 100001)
            {
                hashTable[n] = true;
            }
        }

        for(int i = 1; i < 100001; ++i)
        {
            if(hashTable[i] == false)
            {
                return i;
            }
        }
        return 100001;
    }
};