#include <vector>
#include <climits>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <queue>

#define Point pair<int, int>

using namespace std;

class Solution 
{
private:
    int ans;
    int islandSize;
    int doubleIslandSize;
    vector<vector<int>> DP;

    int i1x;
    int i1y;


public:
    void DFS(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= this->islandSize || j >= this->islandSize || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        DFS(i+1, j, grid);
        DFS(i-1, j, grid);
        DFS(i, j+1, grid);
        DFS(i, j-1, grid);      
    }

    void islandDepict(vector<vector<int>>& grid)
    {
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(grid[i][j] == 1)
                {
                    DFS(i, j, grid);
                    return;               
                }
            }
        }    
    }

    void DPFunc(int i , int j, int delta)
    {
        if(i + delta >= this->islandSize || i + delta < 0 || this->DP[i+delta][j] == 0)
        {
            //no need to update.
        }
        else
        {
            this->DP[i+delta][j] = min(this->DP[i][j]+1, this->DP[i+delta][j]);
        }

        if(j + delta >= this->islandSize  || j + delta < 0 || this->DP[i][j+delta] == 0)
        {
            //no need to update.
        }
        else
        {
            this->DP[i][j+delta] = min(this->DP[i][j]+1, this->DP[i][j+delta]);
        }
    }


    void shortestDistanceToFirstIsland(vector<vector<int>>& grid)
    {
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(grid[i][j] == 2)
                {
                    this->DP[i][j] = 0;
                }
                this->DPFunc(i, j, 1);
            }
        }

        for(int i = this->islandSize-1; i >= 0; --i)
        {
            for(int j = this->islandSize-1; j >= 0; --j)
            {
                this->DPFunc(i, j, -1);
            }
        }  

    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        //find island
        this->islandSize = grid.size();
        this->doubleIslandSize = this->islandSize + this->islandSize;
        this->islandDepict(grid);

        this->ans = INT_MAX;
        
        //DP phase
        this->DP = vector<vector<int>> (this->islandSize, vector<int>(this->islandSize, this->doubleIslandSize));
        this->shortestDistanceToFirstIsland(grid);

        //find ans
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(grid[i][j] == 1 && this->DP[i][j] - 1 < this->ans)
                    this->ans = this->DP[i][j] - 1;
            }
        }


        return this->ans;
    }
};




class Solution2 
{
private:
    int ans;
    int islandSize;
    int doubleIslandSize;
    vector<vector<int>> firstIsland;
    vector<vector<int>> secondIsland;
    vector<vector<int>> visit;

    int i1x;
    int i1y;


public:
    void visitInit()
    {
        this->visit = vector<vector<int>> (this->islandSize, vector<int>(this->islandSize, 0));
    } 

    void DFS(int i, int j, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= this->islandSize || j >= this->islandSize || visit[i][j] != 0 || grid[i][j] == 0)
            return;
        visit[i][j] = 1;

        DFS(i+1, j, grid);
        DFS(i-1, j, grid);
        DFS(i, j+1, grid);
        DFS(i, j-1, grid);      
    }

    bool firstIslandCondition(int& i, int& j, vector<vector<int>>& grid)
    {
        return true;
    }

    bool secondIslandCondition(int& i, int& j, vector<vector<int>>& grid)
    {
        return this->firstIsland.at(i).at(j) == 0;
    }


    vector<vector<int>> islandDepict(vector<vector<int>>& grid, bool (Solution::*condition) (int&, int&, vector<vector<int>>&))
    {
        this->visitInit();
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(grid[i][j] == 1 && (this->*condition)(i, j, grid))
                {
                    DFS(i, j, grid);
                    if(condition == &Solution::firstIslandCondition)
                    {
                        this->i1x = i;
                        this->i1y = j;
                    }
                    return this->visit;                                       
                }
            }
        } 
        return this->visit;     
    }

    void DP(int i , int j, int delta)
    {
        if(i + delta >= this->islandSize || i + delta < 0 || this->visit[i+delta][j] == 0)
        {
            //no need to update.
        }
        else
        {
            this->visit[i+delta][j] = min(this->visit[i][j]+1, this->visit[i+delta][j]);
        }

        if(j + delta >= this->islandSize  || j + delta < 0 || this->visit[i][j+delta] == 0)
        {
            //no need to update.
        }
        else
        {
            this->visit[i][j+delta] = min(this->visit[i][j]+1, this->visit[i][j+delta]);
        }
    }


    void shortestDistanceToFirstIsland()
    {
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(this->firstIsland[i][j] == 1)
                {
                    this->visit[i][j] = 0;
                }
                this->DP(i, j, 1);
            }
        }

        for(int i = this->islandSize-1; i >= 0; --i)
        {
            for(int j = this->islandSize-1; j >= 0; --j)
            {
                this->DP(i, j, -1);
            }
        }  

    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        //find island
        this->islandSize = grid.size();
        this->doubleIslandSize = this->islandSize + this->islandSize;
        this->firstIsland = this->islandDepict(grid, &Solution::firstIslandCondition); 
        this->secondIsland = this->islandDepict(grid, &Solution::secondIslandCondition);

        this->ans = INT_MAX;
        
        //DP phase
        this->visit = vector<vector<int>> (this->islandSize, vector<int>(this->islandSize, this->doubleIslandSize));
        this->shortestDistanceToFirstIsland();

        //find ans
        for(int i = 0; i < this->islandSize; ++i)
        {
            for(int j = 0; j < this->islandSize; ++j)
            {
                if(this->secondIsland[i][j] == 1 && this->visit[i][j] - 1 < this->ans)
                    this->ans = this->visit[i][j] - 1;
            }
        }


        return this->ans;
    }
};



int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << sol.shortestBridge(grid);



    return 0;
}