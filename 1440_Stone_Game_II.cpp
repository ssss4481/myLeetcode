#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// class Solution 
// {    
// public:
//     vector<vector<vector<int>>> dp;
//     int n;

//     int f(int p, int i , int m, vector<int>& piles)
//     {
//         //cout << this->dp.size() << " " << this->dp[0].size() << " " <<  this->dp[0][0].size() << "\n";
//         if(i == this->n)
//             return 0;
//         if(this->dp[p][i][m] != -1)
//             return this->dp[p][i][m];
//         int res = (p == 1) ? 1000000 : -1;
//         int s = 0;
//         for(int x = 1; i <= min(2*m, this->n-i); ++x)
//         {
//             s += piles[i+x-1];
//             if(p == 0)
//             {
//                 res = max(res, s + f(1, i + x, max(m, x), piles));
//             }
//             else
//             {
//                 res = min(res, f(0, i + x, max(m, x), piles));
//             }
//         }
//         this->dp[p][i][m] = res;
//         cout << "before return\n";
//         cout << p << " " << i << " " << m << "\n";

//         return res;
//     }

//     int stoneGameII(vector<int>& piles) 
//     {
//         this->n = piles.size();
//         cout << this->n << "\n";
//         this->dp = vector<vector<vector<int>>> (2, vector<vector<int>> (this->n+1, vector<int> (this->n+1, -1)));
//         for(auto& i: this->dp)
//         {
//             for(auto& j: i)
//             {
//                 for(auto& k : j)
//                 {
//                     cout << k << " ";
//                 }
//                 cout << "\n";
//             }
//         }
        
//         return this->f(0, 0, 1, piles);        
//     }
// };


class Solution2 
{
public:
    int f(int p, int i , int m, vector<int>& piles)
    {
        if(i == piles.size())
            return 0;
        int res = (p == 1)? 1000000 : -1;
        int s = 0;
        for(int x = 1; x <= min(2*m,  int(piles.size()-i)); ++x)
        {
            s += piles[i + x -1];
            if(p == 0)
                res = max(res, s+ this->f(1, i+x, max(m, x), piles));
            else// p == 1
                res = min(res, f(0, i+x, max(m, x), piles));
        }
        return res;
    }

    int stoneGameII(vector<int>& piles) 
    {
        return this->f(0, 0, 1, piles);        
    }
};