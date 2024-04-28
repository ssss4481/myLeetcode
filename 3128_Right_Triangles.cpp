#include <vector>
#include <numeric>

class Solution {
public:
    long long numberOfRightTriangles(std::vector<std::vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        std::vector<long long> rowCount(m, 0);
        std::vector<int> colCount(n, 0);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] > 0){
                    ++rowCount[i];
                    ++colCount[j];
                }
            }
        }
        long long ret = 0;

        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(grid[r][c] > 0){
                    ret += ((rowCount[r]-1) * (colCount[c]-1));
                }
            }
        }
        return ret;
    }
};