#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

//vector< vector<T> > Matrix_generation(T def);
//void printMatrix(vector<vector<T>>& matrix);

void DFS(int x, int y, vector<vector<char>>& grid, vector< vector<bool> > &visit)
{
    int m = grid.size();
    int n = grid[0].size();
    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0' || visit[x][y])
        return;
    visit[x][y] = true;
    DFS(x+1, y, grid, visit);
    DFS(x, y+1, grid, visit);
    DFS(x-1, y, grid, visit);
    DFS(x, y-1, grid, visit);
}

int numIslands(vector<vector<char>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector< vector<bool> > visit (m , vector<bool> (n, false));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(!visit[i][j] && grid[i][j] == '1')
            {
                DFS(i, j, grid, visit);
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    vector< vector<char> > grid;
    matrixMethod::Matrix_generation(grid);
    matrixMethod::printMatrix(grid);
    cout << numIslands(grid) << "\n";

    return 0;
}