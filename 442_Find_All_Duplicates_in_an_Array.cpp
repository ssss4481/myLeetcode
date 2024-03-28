#include <cstdlib>
#include <vector>
class Solution 
{
public:
    std::vector<int> findDuplicates(std::vector<int>& nums) 
    {
        std::vector<int> ret;
        for(auto& n: nums)
        {
            int k = abs(n)-1;
            if(nums[k] < 0)
            {
                ret.push_back(k+1);
            }
            nums[k] = -nums[k];
        }
        return ret;
    }
};