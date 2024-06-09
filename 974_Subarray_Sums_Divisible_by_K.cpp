#include <vector>
#include <unordered_map>
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
    int subarraysDivByK(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> prefix_sum(n+1, 0);
        
        for(int i = 0; i < n; ++i){
            prefix_sum[i+1] = (prefix_sum[i]+nums[i])%k;
        }

        unordered_map<int, int> hashmap;
        int count = 0;

        for(auto& value: prefix_sum){
            if(value < 0){
                value += k;
            }
            count += hashmap[value];
            ++hashmap[value];
        }
        return count;
    }
};