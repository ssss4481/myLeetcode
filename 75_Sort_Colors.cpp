#include <vector>

class Solution 
{
public:
    void sortColors(std::vector<int>& nums) 
    {
        int lo = 0;
        int hi = int(nums.size())-1;
        while (nums[lo] == 0)
        {
            ++lo;
        }
        while (nums[hi] == 2)
        {
            --hi;
        }

        for(int i = lo+1; i <= hi; ++i)
        {
            if(nums[i] == 0)
            {
                std::swap(nums[i--], nums[lo++]);
                continue;
            }
            
            if(nums[i] == 2)
            {
                std::swap(nums[i--], nums[hi--]);
                continue;
            }
        }
    }
};