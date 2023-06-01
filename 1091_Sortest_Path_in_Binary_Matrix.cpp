#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> point;
class Solution 
{
private:
    int ans = -1;

public:
    void BFS(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>> visit (n, vector<int>(n, 0));
        queue<point> BFSQ1;
        queue<point> BFSQ2;
        int pathLength = 1;
        BFSQ1.push(make_pair(0, 0));

        while(!BFSQ1.empty())
        {
            while(!BFSQ1.empty())
            {
                point& p =  BFSQ1.front();
                if(p.first < 0 || p.first >= n || p.second < 0 || p.second >= n || grid[p.first][p.second] == 1 || visit[p.first][p.second] == 1)
                {
                    BFSQ1.pop();             
                    continue;
                } 
                
                if(pathLength < grid[p.first][p.second] || grid[p.first][p.second] == 0)
                    grid[p.first][p.second]= pathLength;
                visit[p.first][p.second] = 1;
                
                for(int i = -1; i <= 1; ++i)
                {
                    for(int j = -1; j <= 1; ++j)
                    {
                        if(i == 0 && j == 0)
                            continue;
                        BFSQ2.push(make_pair(p.first+i, p.second+j));                       
                    }
                }
            }
            ++pathLength;
            BFSQ1.swap(BFSQ2);
        }
    }


    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {               
        int n = grid.size(); 
        if(grid[n-1][n-1] == 1)
            return -1;
        this->BFS(grid);
        return (grid[n-1][n-1] == 0 ? -1 : grid[n-1][n-1]);
    }
};