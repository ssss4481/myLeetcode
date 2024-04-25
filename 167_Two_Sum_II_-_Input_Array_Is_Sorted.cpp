#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int lo = 0;
        int hi = numbers.size()-1;

        while(lo < hi){
            if(numbers[lo] + numbers[hi] == target){
                return {lo+1, hi+1};
            }

            if(numbers[lo] + numbers[hi] < target){
                ++lo;
            }else{
                --hi;
            }
        }
        return {-1, -1};
    }
};