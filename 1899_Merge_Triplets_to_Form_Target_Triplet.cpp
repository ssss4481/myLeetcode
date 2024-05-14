#include <iostream>
#include <vector>

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool fit[3] = {false};
        for(auto& t: triplets){
            if(t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]){
                for(int j = 0; j < 3; ++j){
                    if(t[j] == target[j]){
                        fit[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < 3; ++i){
            if(!fit[i]){
                return false;
            }
        }

        return true;
    }
};