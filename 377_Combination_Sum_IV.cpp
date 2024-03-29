#include <vector>

class Solution 
{
public:
    std::vector<int> dp;

    int combinationSum4(std::vector<int>& nums, int target)     
    {
        this->dp = std::vector<int> (target+1, -1);
        this->dp[0] = 1;
        backTrack(nums, target);
        return this->dp[target];    
    }

    int backTrack(std::vector<int>& nums, int target)
    {
        if(target < 0)
        {
            return 0;
        }
        if(this->dp[target] == -1)
        {
            int result = 0;
            for(auto&num : nums)
            {
                result += backTrack(nums, target-num);
            }
            this->dp[target] = result;
        }
        return this->dp[target];        
    }

};