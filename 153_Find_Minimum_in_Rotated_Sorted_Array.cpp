#include <vector>

class Solution 
{
public:
    int findMin(std::vector<int>& nums) 
    {
        if(nums.back() > nums.front())
        {
            return nums.front();
        }

        return binarySearch(nums, 0, nums.size()-1);
    }

    int binarySearch(std::vector<int>& nums, int lo, int hi)
    {
        if(lo+1 >= hi)
        {
            return nums[lo] < nums[hi] ? nums[lo] : nums[hi];
        }

        int mid = (lo+hi)/2;

        if(nums[mid] < nums[mid-1])
        {
            return nums[mid];
        }
        else if(nums[mid] > nums[hi])
        {
            return binarySearch(nums, mid, hi);
        }
        else
        {
            return binarySearch(nums, lo, mid);
        }
    }
};