#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> ret(2*n);
        int k = 0;
        for(int i = 0; i < n; ++i)
        {
            ret[k] = nums[i];
            k += 2;
        }
        k = 1;
        for(int i = n; i < 2*n; ++i)
        {
            ret[k] = nums[i];
            k += 2;
        }
        return ret;
    }

};