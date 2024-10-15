#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> result(arr.size());
        unordered_map<int, int> val_to_rank;
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());

        int rank = 1;
        
        for(auto& val: copy){
            if(val_to_rank.count(val) == 0){
                val_to_rank[val] = rank++;
            }
        }

        for(int i = 0; i < arr.size(); ++i){
            result[i] = val_to_rank[arr[i]];
        }

        return result;
    }
};