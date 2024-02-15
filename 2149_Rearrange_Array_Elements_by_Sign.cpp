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
    std::vector<int> rearrangeArray(std::vector<int>& nums) 
    {
        std::vector<int> ret(nums.size());
        int pi = 0;
        int ni = 1;
        for(auto& n : nums)
        {
            if(n < 0)
            {
                ret[ni] = n;
                ni += 2;
            }
            else
            {
                ret[pi] = n;
                pi += 2;
            }
        }
        return ret;
    }
};

class Solution2
{
public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) 
    {
        std::vector<int> positive(nums.size()/2);
        std::vector<int> negative(nums.size()/2);
        int pi = 0;
        int ni = 0;
        for(auto& n: nums)
        {
            if(n < 0)
            {
                negative[ni++] = n;
            }
            else
            {
                positive[pi++] = n;
            }
        }

        pi = 0;
        ni = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] = positive[pi++];
            nums[++i] = negative[ni++];
        }
        return nums;        
    }
};