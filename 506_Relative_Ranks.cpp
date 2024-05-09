#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        auto cmp = [&](int i, int j){
            return score[i] > score[j];
        };

        sort(indices.begin(), indices.end(), cmp);

        vector<string> res(n);
        
        for(int i = 3; i < n; ++i){
            res[indices[i]] = to_string(i+1);
        }

        res[indices[0]] = "Gold Medal";
        if(n > 1){
            res[indices[1]] = "Silver Medal";
        }
        if(n > 2){
            res[indices[2]] = "Bronze Medal";
        }
        return res;
    }
};