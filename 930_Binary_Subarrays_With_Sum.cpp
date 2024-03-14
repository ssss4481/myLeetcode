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
    int numSubarraysWithSum(std::vector<int>& nums, int goal) 
    {
        std::vector<int> ones;
        ones.push_back(-1);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 1)
            {
                ones.push_back(i);
            }
        }
        ones.push_back(int(nums.size()));
 
        int count = 0;  
        if(goal > 0)
        {
            int lo = 1;
            int hi = goal;

            while(hi < ones.size()-1)
            {
                count += (ones[hi+1]-ones[hi])*(ones[lo]-ones[lo-1]);
                ++lo;
                ++hi;
            }
        }
        else
        {
            int lo = 0;
            int hi = 1;

            while(hi < ones.size())
            {
                int base = ones[hi++]-ones[lo++]-1;
                count += (1+base)*base/2;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {0, 1, 0, 1, 1, 0};
    std::cout << Solution().numSubarraysWithSum(nums, 1);
    
    return 0;
}

