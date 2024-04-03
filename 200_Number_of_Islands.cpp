#include <vector>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)        
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }

    void DFS(std::vector<std::vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0';

        DFS(grid, i+1, j);
        DFS(grid, i, j+1);
        DFS(grid, i-1, j);
        DFS(grid, i, j-1);
    }
};