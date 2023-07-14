#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        const int n = nums.size();
        int maxLength = 2;
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        for(int j = 1; j < n; ++j)
        {
            for(int i = 0; i < j; ++i)
            {
                int idx = nums[j] - nums[i] + 500;
                dp[j][idx] = dp[i][idx] + 1;
                maxLength = max(maxLength, dp[j][idx]);
            }
        }
        return maxLength;        
    }
};



class Solution2
{
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<unordered_map<int, int>> lengthMap(n);
        int maxLength = 2;

        for(int j = 1; j < n; ++j)
        {
            for(int i = 0; i < j; ++i)
            {
                int delta = nums[j] - nums[i];
                if(lengthMap[i].count(delta) == 1)
                {
                    lengthMap[j][delta] = lengthMap[i][delta] + 1;
                }
                else
                {
                    lengthMap[j][delta] = 2;
                }
                maxLength = max(maxLength, lengthMap[j][delta]);
            }
        }
        return maxLength;
    }
};



class Solution1//TLE
{
public:
    int findNext(const vector<int>& nums, int index, int delta)
    {
        int current = nums[index];
        int maxLength = 0;
        for(int i = index+1; i < nums.size(); ++i)
        {
            if(nums[i] - current == delta)
            {
                maxLength = max(maxLength, findNext(nums, i, delta));
            }
        }
        return maxLength + 1;
    }


    int longestArithSeqLength(vector<int>& nums) 
    {
        const int n = nums.size();
        int maxLength = 1;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                maxLength = max(maxLength, this->findNext(nums, j, nums[j]-nums[i]) + 1);
            }
        }     
        return maxLength;
    }
};