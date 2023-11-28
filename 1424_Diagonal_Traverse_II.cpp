#include <vector>
#include <unordered_map>
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
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) 
    {
        std::unordered_map<int, std::vector<int>> hashMap;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            for(int j = 0; j < nums[i].size(); ++j)
            {                
                hashMap[i+j].push_back(nums[i][j]);
            }            
        }
        
        std::vector<int> ret;

        for(int i = 0; hashMap.count(i) == 1; ++i)
        {

            ret.insert(ret.end(), hashMap[i].begin(), hashMap[i].end());
        }

        return ret;
    }
};