#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[j]){
                nums[++j] = nums[i];
            }
        }

        return j+1;
        
    }
};