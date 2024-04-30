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
    int maximumGap(std::vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        
        std::vector<std::vector<int>> buckets1(16, std::vector<int>());
        std::vector<std::vector<int>> buckets2(16, std::vector<int>());

        int mask = 0xF;

        for(auto& n: nums){
            buckets1[n & mask].push_back(n);
        }

        for(int r = 1; r <= 7; ++r){
            mask <<= 4;
            for(int i = 0; i < 16; ++i){
                for(int j = 0; j < buckets1[i].size(); ++j){
                    int n = buckets1[i][j];
                    buckets2.at((n & mask)>>(r*4)).push_back(n);
                }
            }
            buckets1.swap(buckets2);
            for(auto& bucket: buckets2){
                bucket.clear();
            }
        }

        int ans = 0;
        bool prev_found = false;
        int prev = 0;
        for(int i = 0; i < 16; ++i){
            for(int j = 0; j < buckets1[i].size(); ++j){
                if(!prev_found){
                    prev_found = true;
                    prev = buckets1[i][j];
                }else{
                    ans = std::max(ans, buckets1[i][j]-prev);
                    prev = buckets1[i][j];
                }
            }
        }
        return ans;
    }
};