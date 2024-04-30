#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        unsigned int bit_xor = 0;
        for(auto& n : nums){
            bit_xor ^= n;
        }
        unsigned diff = (bit_xor & (-bit_xor));

        std::vector<int> res(2, 0);

        for(auto& n : nums){
            if(diff & n){
                res[0] ^= n;
            }else{
                res[1] ^= n;
            }
        }
        return res;        
    }
};