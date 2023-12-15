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
    std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();

        std::vector<int> rowInfo(m, -n);
        std::vector<int> colInfo(n, -m);

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    rowInfo[i] += 2;
                    colInfo[j] += 2;
                }
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                grid[i][j] = rowInfo[i] + colInfo[j];
            }
        }       

        return grid;        
    }
};