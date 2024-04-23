#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        int ret = nums.size()+1;
        for(int i = 0; i < nums.size(); ++i){
            int or_value = 0;
            for(int j = i; j < nums.size(); ++j){
                or_value |= nums[j];
                if(or_value >= k){
                    ret = std::min(ret, j-i+1);
                    break;
                }
            }
        }
        return ret == nums.size()+1 ? -1 : ret;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> nums = {2, 1, 8};
    std::cout << Solution().minimumSubarrayLength(nums, 10);
    return 0;
}
