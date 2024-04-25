#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int j = 0;
        bool second_chance = true;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[j]){
                if(second_chance){
                    second_chance = false;
                    nums[++j] = nums[i];
                }
            }else{
                nums[++j] = nums[i];
                second_chance = true;
            }
        }
        return j+1;
    }

};