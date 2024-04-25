#include <vector>
#include <utility>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int hi = nums.size()-1;
        for(int i = 0; i <= hi; ++i){
            if(nums[i] == val){
                std::swap(nums[i], nums[hi]);
                --hi;
                --i;
            }
        }
        while(hi >= 0 && nums[hi] == val){
            --hi;
        }
        return hi+1;
    }
};