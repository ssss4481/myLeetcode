#include <vector>
#include <algorithm>

class Solution {//recursive without copy
public:
    int maxSubArray(std::vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    
    int maxSubArray(std::vector<int>& nums, int lo, int hi){
        if(lo > hi){
            return INT_MIN;
        }
        if(lo == hi){
            return nums[lo];
        }
        int mid = lo + (hi-lo)/2;

        int leftSum = maxSubArray(nums, lo, mid-1);
        int midSum = maxCrossArray(nums, lo, hi);
        int rightSum = maxSubArray(nums, mid+1, hi);

        return std::max({leftSum, midSum, rightSum});
    }

    int maxCrossArray(std::vector<int>& nums, int lo, int hi){
        int mid = lo+(hi-lo)/2;
        int sum = nums[mid];
        int opt = sum;
        
        for(int i = mid-1; i >= lo; --i){            
            sum += nums[i] ;
            opt = std::max(opt, sum);
        }

        sum = opt;

        for(int i = mid+1; i <= hi; ++i){
            sum += nums[i] ;
            opt = std::max(opt, sum);            
        }

        return opt;
    }

};


class Solution1 {//recursive
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 0){
            return INT_MIN;
        } 
        if(nums.size() == 1){
            return nums[0];
        }

        auto mid = nums.begin() + nums.size()/2;

        auto leftArr = std::vector<int>(nums.begin(), mid);
        auto rightArr = std::vector<int>(mid+1, nums.end());

        int leftSum = maxSubArray(leftArr);
        int midSum = maxCrossArray(nums);
        int rightSum = maxSubArray(rightArr);

        return std::max({leftSum, midSum, rightSum});
    }

    int maxCrossArray(std::vector<int>& nums){
        int mid = nums.size()/2;
        int sum = nums[mid];
        int opt = sum;
        
        for(int i = mid-1; i >= 0; --i){            
            sum += nums[i] ;
            opt = std::max(opt, sum);
        }

        sum = opt;

        for(int i = mid+1; i < nums.size(); ++i){
            sum += nums[i] ;
            opt = std::max(opt, sum);            
        }

        return opt;
    }

};


class Solution2 {//DP
public:
    int maxSubArray(std::vector<int>& nums) {
        int opt = nums[0];
        int cur = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(cur < 0){
                cur = nums[i];
            }else{
                cur += nums[i];
            }
            opt = std::max(cur, opt);
        }
        return opt;
    }
};