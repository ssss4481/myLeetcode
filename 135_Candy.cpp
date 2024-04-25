#include <vector>
#include <numeric>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        const int n = ratings.size();
        std::vector<int> distribution(n, 1);

        for(int i = 0; i < n-1; ++i){
            if(ratings[i] < ratings[i+1]){
                if(distribution[i+1] <= distribution[i]){
                    distribution[i+1] = distribution[i]+1;
                }
            }
        }

        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                if(distribution[i] <= distribution[i+1]){
                    distribution[i] = distribution[i+1]+1;
                }
            }
        }

        return std::accumulate(distribution.begin(), distribution.end(), 0);
    }
};