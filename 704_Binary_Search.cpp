#include <vector>
using namespace std;

class Solution
{
public:
    int search_helper(vector<int>& nums, int target, int lo, int hi)
    {
        if(hi - lo <= 1)
        {
            if(nums[lo] == target)
                return lo;
            else if(nums[hi] == target)
                return hi;
            else
                return -1;
        }
        int mid = (lo+hi)/2;
        if(nums[mid] < target)
            return search_helper(nums, target, mid, hi);
        else if(nums[mid] == target)
            return mid;
        else
            return search_helper(nums, target, lo, mid);
    }
    int search(vector<int>& nums, int target)
    {
        return search_helper(nums, target, 0, nums.size()-1);
    }
};