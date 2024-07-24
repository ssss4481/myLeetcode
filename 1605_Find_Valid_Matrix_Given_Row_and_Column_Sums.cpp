#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

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
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size();
        const int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        long long sum = accumulate(rowSum.begin(), rowSum.end(), 0LL);
        int i = 0;

        while(sum > 0){
            for(int j = 0; j < n && rowSum[i] > 0; ++j){
                matrix[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= matrix[i][j];
                colSum[j] -= matrix[i][j];
                sum -= matrix[i][j];
            }
            ++i;
        }
        return matrix;
    }
};


class Solution1 {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size();
        const int n = colSum.size();
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        long long sum = accumulate(rowSum.begin(), rowSum.end(), 0LL);

        while(sum > 0){
            auto min_row = min_element(rowSum.begin(), rowSum.end());
            auto min_col = min_element(colSum.begin(), colSum.end());

            int min_val = min(*min_row, *min_col);

            int x = min_row-rowSum.begin();
            int y = min_col-colSum.begin();

            matrix[x][y] = min_val;
            rowSum[x] -= min_val;
            colSum[y] -= min_val;
            sum -= min_val;

            if(rowSum[x] == 0){
                rowSum[x] = INT_MAX;
            }else{
                colSum[y] = INT_MAX;
            }
        }
        return matrix;
    }
};