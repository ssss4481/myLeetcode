#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

class Solution {
public:
    int medianOfUniquenessArray(std::vector<int>& nums) {
        int n = (1+nums.size())*nums.size()/2/2;
        int hashmap[100001];
        int ans = 1;
        while(n > 0){
            memset(hashmap, 0, sizeof(hashmap));
            int count = 0;
            int lo = 0; 
            int hi = 0;
            while(hi < nums.size()){
                while(hi < nums.size() && count < ans){
                    if(++hashmap[nums[hi++]] == 1){
                        ++count;
                    }
                }
                if(count != ans){
                    break;
                }
                int temp = hi;
                while(temp < nums.size() && hashmap[nums[temp++]] != 0){
                    --n;
                }
                while (count == ans){
                    --n;
                    if(--hashmap[nums[lo++]] == 0){
                        --count;
                    }                    
                }
                if(n < 0){
                    return ans;
                }
            }
            ++ans;
        }
        return ans;
    }
};