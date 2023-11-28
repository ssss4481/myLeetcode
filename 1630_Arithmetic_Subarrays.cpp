#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
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
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) 
    {
        auto check = [&](const int& l, const int& r)
        {
            std::vector<int> copy(nums.begin()+l, nums.begin()+r+1);
            std::sort(copy.begin(), copy.end());
            int diff = copy[1] - copy[0];
            for(int i = 2; i < copy.size(); ++i)
            {
                if(copy[i]-copy[i-1] != diff)
                {
                    return false;
                }
            }
            return true;
        };

        std::vector<bool> ret(l.size());
        
        for(int i = 0; i < l.size(); ++i)
        {
            ret[i] = check(l[i], r[i]);
        }

        return ret; 
    }
};






class Solution //Slow
{
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) 
    {
        auto check = [&nums](const int& l, const int r)
        {
            int maxVal = INT32_MIN;
            int minVal = INT32_MAX;
            std::unordered_set<int> hashSet;
            
            for(int i = l; i <= r; ++i)
            {
                maxVal = std::max(maxVal, nums[i]);
                minVal = std::min(minVal, nums[i]);
                hashSet.insert(nums[i]);
            }

            if((maxVal-minVal) % (r - l) != 0)
            {
                return false;
            }

            int diff = (maxVal-minVal) / (r - l);
            minVal += diff;

            while(minVal < maxVal)
            {
                if(hashSet.count(minVal) == 0)
                {
                    return false;
                }
                minVal += diff;
            }
            return true;
        };

        std::vector<bool> ret(l.size());

        for(int i = 0; i < l.size(); ++i)
        {
            ret[i] = check(l[i], r[i]);
        }

        return ret;        
    }
};

