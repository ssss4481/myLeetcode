#include <vector>
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
    bool canJump(std::vector<int>& nums) 
    {
        int i = 0;
        int maxIdx = i + nums[i];
        while(maxIdx < nums.size()-1)
        {       
            int nextMax = 0;
            for(int j = i; j <= maxIdx; ++j)
            {
                nextMax = std::max(nextMax, j + nums[j]);
            }
            if(nextMax <= maxIdx)
            {
                return false;
            }
            i = maxIdx+1;
            maxIdx = nextMax;
        }
        return true;
    }
};