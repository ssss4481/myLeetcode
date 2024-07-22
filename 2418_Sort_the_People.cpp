#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>

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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n = names.size();

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        auto cmp = [&](int i, int j){
            return heights[i] > heights[j];
        };

        sort(indices.begin(), indices.end(), cmp);

        vector<string> result(n);

        for(int i = 0; i < n; ++i){
            result[i] = move(names[indices[i]]);
        }

        return result;
    }
};

