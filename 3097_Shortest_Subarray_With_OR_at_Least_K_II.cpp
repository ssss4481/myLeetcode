#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {

        int bitCount[32] = {0};
        int lo = 0;
        int or_value = 0;

        int ret = nums.size()+1;

        for(int i = 0; i < nums.size(); ++i){
            or_value |= nums[i];
            add_bitcount(bitCount, nums[i]);
            if(or_value >= k){
                while(lo <= i && or_value >= k){
                    or_value -= sub_bitcount(bitCount, nums[lo++]);
                }
                int potential = i - lo + 2;
                ret = std::min(potential, ret);
            }
        }
        
        return ret <= nums.size() ? ret : -1;
    }

    void add_bitcount(int bitCount[], int value){
        for(int i = 0; i < 32 && value != 0; ++i){
            if(value & 1){
                ++bitCount[i];
            }
            value >>= 1;
        }
    }

    int sub_bitcount(int bitCount[], int value){
        int sub = 0;
        for(int i = 0; i < 32 && value != 0; ++i){
            if(value & 1){
                if(--bitCount[i] == 0){
                    sub += (1 << i);
                }
            }
            value >>= 1;
        }
        return sub;
    }
};