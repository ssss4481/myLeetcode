#include <vector>
#include <algorithm>

class Solution 
{
public:
    int numSquares(int n) 
    {
        std::vector<int> dp(n+1, 0);
        std::vector<int> squares;
        for(int i = 1; i*i < n+1; ++i)
        {
            dp[i*i] = 1;
            squares.push_back(i*i);
        }      

        for(int i = 1; i < n+1; ++i)
        {
            if(dp[i] == 0)
            {
                dp[i] = i;
                for(int j = 0; j < squares.size() && squares[j] < i; ++j)
                {
                    dp[i] = std::min(1 + dp[i-squares[j]], dp[i]);
                }             
            }
        }

        return dp[n];        
    }
};