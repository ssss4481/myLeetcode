#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max_res = INT_MIN;
        int min_res = INT_MAX;
        int cur = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(cur < 0){
                cur = nums[i];
            }else{
                cur += nums[i];
            }
            if(cur > max_res){
                max_res = cur;
            }
        }

        cur = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(cur > 0){
                cur = nums[i];
            }else{
                cur += nums[i];
            }

            if(cur < min_res){
                min_res = cur;
            }
        }

        if(sum == min_res){
            return max_res;
        }
        return max(sum-min_res, max_res);
    }
};