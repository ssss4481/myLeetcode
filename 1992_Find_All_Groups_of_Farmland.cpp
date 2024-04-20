#include <vector>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        const int m = land.size();
        const int n = land[0].size();
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(land[i][j] == 1){
                    std::vector<int> square = {i, j, i, j};
                    int& x = square[2];
                    int& y = square[3];
                    while(x < m-1 && land[x+1][j] == 1){
                        land[x][j] = 0;
                        ++x;
                    }
                    land[x][j] = 0;

                    while(y < n-1 && land[i][y+1] == 1){
                        land[i][y] = 0;
                        ++y;
                    }
                    land[i][y] = 0;

                    for(int a = i; a <= x; ++a){
                        for(int b = j; b <= y; ++b){
                            land[a][b] = 0;
                        }
                    }
                    ret.push_back(square);
                }
            }
        }
        return ret;
    }
};

class Solution1 {
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land) {
        const int m = land.size();
        const int n = land[0].size();
        std::vector<std::vector<int>> ret;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(land[i][j] == 1){
                    std::vector<int> square = {i, j, 0, 0};
                    DFS(land, square, i, j);
                    ret.push_back(square);
                }
            }
        }
        return ret;
    }

    void DFS(std::vector<std::vector<int>>& land, std::vector<int>& square, int i, int j){
        if(land[i][j] == 0){
            return;
        }
        // square[0] = std::min(square[0], i);
        // square[1] = std::min(square[1], j);
        square[2] = std::max(square[2], i);
        square[3] = std::max(square[3], j);
        land[i][j] = 0;
        // if(i > 0){
        //     DFS(land, square, i-1, j);
        // }
        if(i < land.size()-1){
            DFS(land, square, i+1, j);
        }
        // if(j > 0){
        //     DFS(land, square, i, j-1);
        // }
        if(j < land[0].size()-1){
            DFS(land, square, i, j+1);
        }
    }
};