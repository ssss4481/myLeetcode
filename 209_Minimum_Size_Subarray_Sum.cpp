#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        const int n = nums.size();
        int lo = 0;
        int hi = 0;
        int sum = nums[0];
        int ret = n+1;

        while(hi < n)
        {
            if(sum < target)
            {
                ++hi;
                if(hi < n)
                {
                    sum += nums[hi];
                }
            }
            else
            {
                ret = min(ret, hi-lo+1);
                sum -= nums[lo];
                ++lo;
            }
        }

        return ret == n+1 ? 0 : ret;        
    }
};