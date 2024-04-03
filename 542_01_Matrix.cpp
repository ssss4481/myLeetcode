#include <iostream>
#include <vector>
#include <algorithm>

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