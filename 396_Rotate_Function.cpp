#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int current = 0;
        int res = INT_MIN;
        for(int i = 0; i < n; ++i){
            current += i*nums[i];
        }
        res = max(res, current);

        for(int i = 1; i < n; ++i){
            current = current + sum - n*nums[n-i];
            res = max(res, current);
        }
        return res;
    }
};


class Solution1 {//TLE
public:
    int maxRotateFunction(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ress(nums.size(), 0);

        for(int i = 0; i < ress.size(); ++i){
            for(int j = 0; j < nums.size(); ++j){
                ress[i] += nums[j] * ((j+i)%n);
            }
        }
        return *max_element(ress.begin(), ress.end());
    }
};