#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        unordered_map<int, int> subset;
        backtracking(nums, k, subset, 0, result);
        return result-1;
    }
    void backtracking(const vector<int>& nums, const int k, unordered_map<int, int>& subset, int idx, int& result){
        if(idx == nums.size()){
            ++result;
            return;
        }
        int current = nums[idx];
        if(subset[current-k] == 0){
            ++subset[current];
            backtracking(nums, k, subset, idx+1, result);
            --subset[current];
        }
        backtracking(nums, k, subset, idx+1, result);
    }
};