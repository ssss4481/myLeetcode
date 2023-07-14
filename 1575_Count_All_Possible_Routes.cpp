#include <vector>
#include <algorithm>

using namespace std;


class Solution 
{
private:
    vector<vector<int>> dp;

public:
    int sol(vector<int>& locations, int currCity, int finish, int fuel)
    {
        if(fuel < 0)
        {
            return 0;
        }

        if(this->dp[currCity][fuel] >= 0)
        {
            return dp[currCity][fuel];
        }

        int ans = (currCity == finish) ? 1 : 0;

        for(int nextCity = 0; nextCity < locations.size(); ++nextCity)
        {
            if(nextCity != currCity)
            {
                ans += this->sol(locations, nextCity, finish, fuel - abs(locations[nextCity] - locations[currCity]));
                ans %= 1000000007;                
            }
        }        
        dp[currCity][fuel] = ans;

        return ans;
    }


    int countRoutes(vector<int>& locations, int start, int finish, int fuel) 
    {
        const int n = locations.size();
        this->dp = vector<vector<int>> (n, vector<int> (1+fuel, -1));

        return this->sol(locations, start, finish, fuel);       
    }
};