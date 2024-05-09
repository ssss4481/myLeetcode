#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i < triangle.size(); ++i){
            auto& prev_row = triangle[i-1];
            auto& current_row = triangle[i];

            current_row.front() += prev_row.front();
            current_row.back() += prev_row.back();

            for(int j = 1; j < current_row.size()-1; ++j){
                current_row[j] += min(prev_row[j-1], prev_row[j]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};