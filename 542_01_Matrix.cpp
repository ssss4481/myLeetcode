#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

struct Pos{
    int x;
    int y;
    Pos(){}
    Pos(int _x, int _y):x{_x}, y{_y}{}
};

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        
        const std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        const int m = mat.size();
        const int n = mat[0].size();
        std::queue<Pos> Q;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    Q.push(Pos(i, j));
                }else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!Q.empty()){
            auto src = Q.front();
            Q.pop();
            for(auto& dir: dirs){
                int x = src.x + dir[0];
                int y = src.y + dir[1];
                if(x < 0 || x >= m || y < 0 || y >= n || mat[x][y] <= mat[src.x][src.y]+1){
                    continue;
                }
                mat[x][y] = mat[src.x][src.y]+1;
                Q.push(Pos(x, y));
            }
        }

        return mat;
    }
};


class Solution1 
{
public:
    void updateDPElement(std::vector<std::vector<int>>& dp, int i, int j, int delta)
    {
        if(!(i + delta >= dp.size() || i + delta < 0 || dp[i+delta][j] == 0))
        {
            dp[i+delta][j] = std::min(dp[i][j]+1, dp[i+delta][j]);
        }

        if(!(j + delta >= dp[0].size() || j +delta < 0 || dp[i][j+delta] == 0))
        {
            dp[i][j+delta] = std::min(dp[i][j]+1, dp[i][j+delta]);
        }
    }

    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) 
    {
        std::vector<std::vector<int>> dp(mat.size(), std::vector<int>(mat[0].size(), 20000));
        
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 0)
                {
                    dp[i][j] = 0;
                }

                updateDPElement(dp, i, j, 1);
                
            }
        }
        for(int i = mat.size()-1; i >=0 ; --i)
        {
            for(int j = mat[0].size()-1; j >= 0; --j)
            {
                updateDPElement(dp, i, j, -1);
            }
        }    
        return dp;
    }
};