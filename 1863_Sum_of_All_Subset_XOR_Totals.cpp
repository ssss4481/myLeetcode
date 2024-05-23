#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum  = 0;
        backtracking(nums, sum);
        return sum;
    }

    void backtracking(const vector<int>& nums, int& sum, int current=0, int index=0){
        if(index == nums.size()){
            sum += current;
            return;
        }

        backtracking(nums, sum, current^nums[index], index+1);
        backtracking(nums, sum, current, index+1);
    }
};