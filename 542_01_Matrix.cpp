#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void updateDPElement(vector<vector<int>>& dp, int i, int j, int delta)
    {
        if(i + delta >= dp.size() || i + delta < 0 || dp[i+delta][j] == 0)
        {
            //no need to update.
        }
        else
        {
            dp[i+delta][j] = min(dp[i][j]+1, dp[i+delta][j]);
        }

        if(j + delta >= dp[0].size() || j +delta < 0 || dp[i][j+delta] == 0)
        {
            //no need to update.
        }
        else
        {
            dp[i][j+delta] = min(dp[i][j]+1, dp[i][j+delta]);
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), 20000));
        
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