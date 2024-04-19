#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    perimeter += 4 - CountOfNeighbor(grid, i, j);
                }
            }
        }
        return perimeter;
    }

    int CountOfNeighbor(std::vector<std::vector<int>>& grid, int i, int j){
        int count = 0;
        if(i > 0 && grid[i-1][j] == 1){
            ++count;
        }

        if(i < grid.size()-1 && grid[i+1][j] == 1){
            ++count;
        }

        if(j > 0 && grid[i][j-1] == 1){
            ++count;
        }

        if(j < grid[0].size()-1 && grid[i][j+1] == 1){
            ++count;
        }
        return count;
    }
};