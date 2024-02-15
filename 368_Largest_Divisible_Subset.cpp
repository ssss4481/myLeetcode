#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
class Solution 
{
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) 
    {
        std::sort(nums.rbegin(), nums.rend());
        std::vector<int> answer;
        std::vector<int> parent(nums.size(), -1);
        std::vector<int> dp(nums.size(), 1);

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i+1; j < nums.size(); ++j)
            {
                if(nums[i] % nums[j] == 0 && dp[i]+1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    parent[j] = i;
                }
            }
        }

        int optimalIdx = static_cast<int>(std::max_element(dp.begin(), dp.end())-dp.begin());
        do
        {
            answer.push_back(nums[optimalIdx]);
            optimalIdx = parent[optimalIdx];
        }while(optimalIdx != -1);

        return answer;     
    }
};