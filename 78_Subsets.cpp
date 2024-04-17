#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> subset;
        backtracking(ret, nums, subset, 0);
        return ret;
    }

    void backtracking(std::vector<std::vector<int>>& ret, std::vector<int>& nums, std::vector<int>& subset, int i){
        if(i == nums.size()){
            ret.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtracking(ret, nums, subset, i+1);
        subset.pop_back();
        backtracking(ret, nums, subset, i+1);
    }
};