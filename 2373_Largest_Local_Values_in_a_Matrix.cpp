#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));

        for(int i = 0; i < n-2; ++i){
            for(int j = 0; j < n-2; ++j){
                res[i][j] = largest(grid, i+1, j+1);
            }
        }
        return res;
    }

    int largest(vector<vector<int>>& grid, int x, int y){
        int res = 0;
        for(int dx = -1; dx <= 1; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
                res = max(res, grid[x+dx][y+dy]);
            }
        }
        return res;
    }
};