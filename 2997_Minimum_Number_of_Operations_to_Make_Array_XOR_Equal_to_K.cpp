#include <vector>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int t = 0;
        for(auto& n: nums){
            t ^= n;
        }

        int op = 0;

        while(t != k){
            if((t&1) != (k&1)){
                ++op;
            }
            t >>= 1;
            k >>= 1;
        }

        return op;
    }
};