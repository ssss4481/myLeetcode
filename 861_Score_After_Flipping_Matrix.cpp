#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        for(int i = 0; i < m; ++i){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                    }else{
                        grid[i][j] = 1;
                    }
                }
            }
        }        

        for(int j = 0; j < n; ++j){
            int oneCount = 0;
            for(int i = 0; i < m; ++i){
                if(grid[i][j] == 1){
                    ++oneCount;
                }
            }
            if(oneCount < m - oneCount){
                for(int i = 0; i < m; ++i){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                    }else{
                        grid[i][j] = 1;
                    }
                }
            }
        }

        int res = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    res += (1 << (n-1-j));
                }
            }
        }

        return res;
    }
};