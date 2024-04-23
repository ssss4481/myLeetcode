#include <vector>

class Solution {
public:
    int minimumLevels(std::vector<int>& possible) {
        std::vector<int> prefix_sum(possible.size());
        prefix_sum[0] = possible[0] == 1 ? 1 : -1;
        for(int i = 1; i < possible.size(); ++i){
            if(possible[i] > 0){
                prefix_sum[i] = prefix_sum[i-1] + 1;
            }else{
                prefix_sum[i] = prefix_sum[i-1] - 1;
            }
        }
        int ret = possible.size();

        for(int i = 0; i < possible.size()-1; ++i){
            if(prefix_sum.back() - prefix_sum[i] < prefix_sum[i]){
                return i+1;
            }
        }
        return -1;
    }
};