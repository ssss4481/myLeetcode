#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> hashset;
        int res = -1;
        for(auto& n:  nums){
            if((n > 0 && hashset.count(-n) == 1) || (n < 0 && hashset.count(-n) == 1)){
                res = std::max(res, std::abs(n));
            }
            hashset.insert(n);
        }
        return res;
    }
};