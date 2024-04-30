#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if((mid - 1 < 0 || nums[mid] > nums[mid-1]) && (mid + 1 >= nums.size() || nums[mid] > nums[mid+1])){
                return mid;
            }

            if(mid - 1 < 0 || nums[mid] > nums[mid-1]){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return lo;
    }
};