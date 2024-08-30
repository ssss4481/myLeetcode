#include <iostream>
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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int m = grid1.size();
        const int n = grid1.front().size();

        int result = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid2[i][j] == 1 && DFS(grid1, grid2, i, j, m, n)){
                    ++result;
                }
            }
        }
        return result;
    }

    bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, const int m, const int n){

        bool isSub = (grid1[i][j] == 1);

        grid2[i][j] = 2;

        if(i+1 < m && grid2[i+1][j] == 1){
            isSub = (DFS(grid1, grid2, i+1, j, m, n) && isSub);
        }
        if(i-1 >= 0 && grid2[i-1][j] == 1){
            isSub = (DFS(grid1, grid2, i-1, j, m, n) && isSub);
        }
        if(j+1 < n && grid2[i][j+1] == 1){
            isSub = (DFS(grid1, grid2, i, j+1, m, n) && isSub);
        }
        if(j-1 >= 0 && grid2[i][j-1] == 1){
            isSub = (DFS(grid1, grid2, i, j-1, m, n) && isSub);
        }                        

        return isSub;
    }

};