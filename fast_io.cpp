#include <vector>
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
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int cost = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] <= nums[i-1]){
                cost += (nums[i-1]+1)-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }

        return cost;
    }
};