#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        int result = INT_MIN;
        
        int row_max = grid.back().back();
        for(int j = n-2; j >= 0; --j){
            result = max(result, row_max-grid.back()[j]);
            row_max = max(row_max, grid.back()[j]);
        }

        for(int i = m-2; i >= 0; --i){
            result = max(result, grid[i+1][n-1] - grid[i][n-1]);
            grid[i][n-1] = max(grid[i+1][n-1], grid[i][n-1]);
            row_max = grid[i][n-1];
            for(int j = n-2; j >= 0; --j){
                result = max({result, grid[i+1][j] - grid[i][j], row_max-grid[i][j]});
                grid[i][j] = max(grid[i+1][j], grid[i][j]);
                row_max = max(row_max, grid[i][j]);
            }
        }
        return result;
    }
};