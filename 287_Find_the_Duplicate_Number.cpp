#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int s = 0;
        int f = 0;

        while(s != f){
            s = nums[s];
            f = nums[f];
        }
        int t = 0;

        while(s != t){
            s = nums[s];
            t = nums[f];
        }

        return s;
    }
};



class Solution1 {
public:
    int findDuplicate(std::vector<int>& nums) {
        int lo = 1;
        int hi = nums.size();

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            int count = 0;
            for(auto& n : nums){
                if(n <= mid){
                    ++count;
                }
            }
            if(count <= mid){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        return hi;
    }
};