#include <vector>


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int b = 0;
        for(const auto& n: nums){
            b ^= n;            
        }
        return b;
    }
};