#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef std::pair<int, int> pi;

class Solution 
{
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) 
    {
        int freshOrange = 0;
        std::vector<pi> Q1;
        std::vector<pi> Q2;

        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    ++freshOrange;
                }
                else if(grid[i][j] == 2)
                {
                    Q1.push_back({i, j});
                }
            }
        }

        if(freshOrange == 0)
        {
            return 0;
        }               

        auto rotting = [&](int i, int j)
        {
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            {
                return;
            }
            --freshOrange;
            Q2.push_back({i, j});
            grid[i][j] = 2;
        };
 

        int time = 0;
        while(!Q1.empty())
        {
            ++time;
            for(auto& rot: Q1)
            {
                const int& i = rot.first;
                const int& j = rot.second;
                rotting(i+1, j);
                rotting(i-1, j);
                rotting(i, j+1);
                rotting(i, j-1);
                if(freshOrange == 0)
                {
                    return time;
                }
            }
            Q1.swap(Q2);
            Q2.clear();
        }
        return -1;        
    }
};