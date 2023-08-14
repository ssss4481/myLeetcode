#include <iostream>
#include <vector>
using namespace std;






class Solution
{
public:
    int limit_i;
    int limit_j;

    bool valid(vector<vector<int>>& obstacleGrid , int i, int j)
    {
        if(i < 0 || j < 0 || i > limit_i || j > limit_j || obstacleGrid[i][j])
        {
            return false;
        }
        return true;
    }

    void accuIfValid(vector<vector<long long>>& dp, vector<vector<int>>& obstacleGrid, int i, int j)
    {
        if(obstacleGrid[i][j])
        {
            return;
        }

        if(valid(obstacleGrid, i-1, j))
        {
            dp[i-1][j] += dp[i][j];
        }

        if(valid(obstacleGrid, i, j-1))
        {
            dp[i][j-1] += dp[i][j];
        }

    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid.back().back())
        {
            return 0;
        }

        vector<vector<long long>> dp (obstacleGrid.size(), vector<long long> (obstacleGrid[0].size(), 0));
        dp.back().back() = 1;
    
        limit_i = dp.size() - 1;
        limit_j = dp[0].size() - 1;

        int start_i = limit_i;
        int limit_sum = limit_i+limit_j;

        while(start_i >= 0)
        {
            int i = start_i;
            int j = limit_j;
            while(1)
            {
                if(i > limit_i || j < 0)
                {
                    break;
                }
                else
                {
                    accuIfValid(dp, obstacleGrid, i, j);
                }
                ++i;
                --j;
            }
            --start_i;
        }
        ++start_i;
        --limit_j;
        while(limit_j >= 0)
        {
            int i = start_i;
            int j = limit_j;
            while(1)
            {
                if(i > limit_i || j < 0)
                {
                    break;
                }
                else
                {
                    accuIfValid(dp, obstacleGrid, i, j);
                }
                ++i;
                --j;
            }
            --limit_j;
        }  
            return int(dp[0][0]);
    }
};






class Solution3
{
public:
    int goal_i;
    int goal_j;
    int count;
    vector<vector<int>> confirmed;

    bool backTracking(vector<vector<int>>& obstacleGrid, int i, int j)
    {
        if(i > goal_i || j > goal_j || obstacleGrid[i][j])
        {
            return false;
        }

        if(confirmed[i][j] > 0)
        {
            this->count += confirmed[i][j];
            return true;
        }

        bool r1 = backTracking(obstacleGrid, i+1, j);
        bool r2 = backTracking(obstacleGrid, i, j+1);
        if(r1 || r2)
        {
            if(i+1 <= goal_i)
            {
                confirmed[i][j] += confirmed[i+1][j];
            }
            if(j+1 <= goal_j)
            {
                confirmed[i][j] += confirmed[i][j+1];
            }
            return true;
        }            
        return false;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid.back().back())
        {
            return 0;
        }
        this->goal_i = obstacleGrid.size()-1;
        this->goal_j = obstacleGrid[0].size()-1;
        this->count = 0;
        this->confirmed = vector<vector<int>> (goal_i+1, vector<int>(goal_j+1, 0));
        this->confirmed[goal_i][goal_j] = 1;
        backTracking(obstacleGrid, 0, 0);     
        return this->count;
    }
};



class Solution2 
{
public:
    int goal_i;
    int goal_j;
    int count;

    void backTracking(vector<vector<int>>& obstacleGrid, int i, int j)
    {

        if(i > goal_i || j > goal_j || obstacleGrid[i][j])
        {
            return;
        }
        if(i == goal_i && j == goal_j)
        {
            ++this->count;
            return;
        }
        backTracking(obstacleGrid, i+1, j);
        backTracking(obstacleGrid, i, j+1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        if(obstacleGrid.back().back())
        {
            return 0;
        }
        this->goal_i = obstacleGrid.size()-1;
        this->goal_j = obstacleGrid[0].size()-1;
        this->count = 0;
        backTracking(obstacleGrid, 0, 0);     
        return this->count;
    }
};

void imple1()
{
    vector<vector<int>> t = {{1,2,3}, {4,5,6}};
    int limit_i = t.size() - 1;
    int limit_j = t[0].size() - 1;

    int start_i = limit_i;
    int start_j = limit_j;
    int limit_sum = limit_i+limit_j;

    while(limit_sum >= 0)
    {
        int i = start_i;
        int j = start_j;
        while(1)
        {
            if(i < 0 || j < 0 || i > limit_i || j > limit_j)
            {
                if(i > limit_i)
                {
                    break;
                }
            }
            else
            {
                cout << t[i][j] << '\n';
            }
            ++i;
            --j;
        }
        --limit_sum;
        --start_i;

    }    
}

void imple2()
{

    vector<vector<int>> t = {{1,2}, {4,5}, {7, 8}};
    int limit_i = t.size() - 1;
    int limit_j = t[0].size() - 1;

    int start_i = limit_i;
    int limit_sum = limit_i+limit_j;

    while(start_i >= 0)
    {
        int i = start_i;
        int j = limit_j;
        while(1)
        {
            if(i > limit_i || j < 0)
            {
                break;
            }
            else
            {
                cout << t[i][j] << '\n';
            }
            ++i;
            --j;
        }
        --start_i;
    }
    ++start_i;
    --limit_j;
    while(limit_j >= 0)
    {
        int i = start_i;
        int j = limit_j;
        while(1)
        {
            if(i > limit_i || j < 0)
            {
                break;
            }
            else
            {
                cout << t[i][j] << '\n';
            }
            ++i;
            --j;
        }
        --limit_j;
    }


}

int main(int argc, char const *argv[])
{

    imple2();

    
    return 0;
}
