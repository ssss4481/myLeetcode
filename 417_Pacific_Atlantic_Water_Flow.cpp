#include <vector>
#include <unordered_set>
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
    int m;
    int n;

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) 
    {
        this->m = heights.size();
        this->n = heights[0].size();
        std::vector<std::vector<int>> ret;

        if(m == 1 || n == 1)
        {
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    ret.push_back({i, j});
                }
            }
            return ret;
        }

        auto visited1 = std::vector<std::vector<bool>> (this->m, std::vector<bool>(this->n, 0));
        auto visited2 = std::vector<std::vector<bool>> (this->m, std::vector<bool>(this->n, 0));

        for(int i = 0; i < m; ++i)
        {
            this->DFS(i, 0, visited1, -1, heights);
        }
        for(int i = 1; i < n; ++i)
        {
            this->DFS(0, i, visited1, -1, heights);
        }

        for(int i = 0; i < m; ++i)
        {
            this->DFS(i, this->n-1, visited2, -1, heights);
        }
        for(int i = 0; i < n-1; ++i)
        {
            this->DFS(this->m-1, i, visited2, -1, heights);
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(visited1[i][j] && visited2[i][j])
                {
                    ret.push_back({i, j});
                }    
            }
        }

        return ret;
    }
    
    void DFS(int x, int y, std::vector<std::vector<bool>>& visited, const int& parentHeight, std::vector<std::vector<int>>& heights)
    {
        if(x < 0 || x >= this->m || y < 0 || y >= this->n || heights[x][y] < parentHeight || visited[x][y])
        {
            return;    
        }
        visited[x][y] = true;;
        const int &currentHeight = heights[x][y];
        DFS(x+1, y, visited, currentHeight, heights);
        DFS(x-1, y, visited, currentHeight, heights);
        DFS(x, y+1, visited, currentHeight, heights);
        DFS(x, y-1, visited, currentHeight, heights);
    }

};