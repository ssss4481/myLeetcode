#include <unordered_set>
#include <algorithm>
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
    int longestConsecutive(std::vector<int>& nums) 
    {
        int ret = 0;
        std::unordered_set<int> hashMap(nums.begin(), nums.end());
        for(auto& n : nums)
        {            
            if(hashMap.count(n) != 0)
            {
                int length = 1;
                hashMap.erase(n);
                for(int i = n+1; hashMap.count(i) != 0; ++i)
                {
                    hashMap.erase(i);
                    ++length;
                }

                for(int i = n-1; hashMap.count(i) != 0; --i)
                {
                    hashMap.erase(i);                    
                    ++length;
                }                
                ret = std::max(ret, length);
            }
        }
        return ret;
    }
};
