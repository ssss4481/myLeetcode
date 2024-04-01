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
    int subarraysWithKDistinct(std::vector<int>& nums, int k) 
    {
        std::unordered_map<int, int> intAndCount;
        int lo = 0;
        int hi = 0;
        int ret = 0;
        auto slide = [&]()
        {
            int loLimit = lo;
            while(intAndCount[nums[loLimit]] != 1)
            {
                --intAndCount[nums[loLimit++]];
            }
            int hiLimit = hi;
            while(hiLimit < nums.size() && intAndCount.count(nums[hiLimit]) == 1)
            {
                ++hiLimit;
            }
            ret += (hiLimit-hi+1)*(loLimit-lo+1);
            --intAndCount[nums[loLimit]];
            intAndCount.erase(nums[loLimit]);
            lo = loLimit + 1;
        };

        while(hi < nums.size())
        {
            if(intAndCount.size() < k)
            {
                ++intAndCount[nums[hi]];
                ++hi;
            }
            else if(intAndCount.size() == k)
            {
                slide();
            }
        }

        if(intAndCount.size() ==k)
        {
            slide();
        }
        return ret;
    }
};