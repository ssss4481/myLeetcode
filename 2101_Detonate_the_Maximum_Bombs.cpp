#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;
class Solution 
{
private:
    vector<char> visit;
    int n;
public:    

    long long pow2(int num)
    {
        return static_cast<long long>(num) * num;
    }

    bool bomb1ContainsBomb2(vector<int>& bomb1, vector<int>& bomb2, long long& r_2)
    {
        long long&& x_2 = this->pow2(bomb1[0] - bomb2[0]);
        long long&& y_2 = this->pow2(bomb1[1] - bomb2[1]);
        return x_2 + y_2 <= r_2;
    }
    
    int DFS(vector<vector<int>>& adj, int i)
    {
        if(this->visit[i] == 1)
            return 0;

        visit[i] = 1;
        int acc = 1;
        for(int& j: adj[i])
        {
            acc += DFS(adj, j);
        }
        return acc;
    }


    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        this->n = bombs.size();
        vector<vector<int>> inRange (this->n, vector<int>(0));
        //define inRange[m][this->n], 1: this->n in m's range, 0: not in, -1: not calculated
        //sort(bombs.begin(), bombs.end(), Solution::cmp);
        vector<long long> r_2s (this->n);
        for(int i = 0; i < this->n ; ++i)
        {
            r_2s[i] = static_cast<long long>(bombs[i][2]) * bombs[i][2];
        }

        for(int i = 0; i < this->n; ++i)
        {
            for(int j = 0; j < this->n; ++j)
            {
                if(i != j)
                {                 
                    if(bomb1ContainsBomb2(bombs[i], bombs[j], r_2s[i]))
                        inRange[i].push_back(j);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < this->n; ++i)
        {
            this->visit = vector<char> (this->n, 0);            
            int&& count = this->DFS(inRange, i);
            if(count > ans)
                ans = count;
        }

        return ans;
    }
};





class Solution3 
{
private:
    vector<char> visit;
    int n;
public:   


    long long pow2(int num)
    {
        return static_cast<long long>(num) * num;
    }

    bool bomb1ContainsBomb2(vector<int>& bomb1, vector<int>& bomb2, long long& r_2)
    {
        long long&& x_2 = this->pow2(bomb1[0] - bomb2[0]);
        long long&& y_2 = this->pow2(bomb1[1] - bomb2[1]);
        return x_2 + y_2 <= r_2;
    }
    
    int DFS(vector<vector<int>>& adj, int i)
    {
        if(this->visit[i] == 1)
            return 0;

        visit[i] = 1;
        int acc = 1;
        for(int j = 0; j < adj.size(); ++j)
        {
            if(adj[i][j])
            {
                acc += DFS(adj, j);                
            }
        }
        return acc;
    }


    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        this->n = bombs.size();
        vector<vector<int>> inRange (this->n, vector<int>(this->n, -1));
        //define inRange[m][this->n], 1: this->n in m's range, 0: not in, -1: not calculated
        //sort(bombs.begin(), bombs.end(), Solution::cmp);
        vector<long long> r_2s (this->n);
        for(int i = 0; i < this->n ; ++i)
        {
            r_2s[i] = static_cast<long long>(bombs[i][2]) * bombs[i][2];
        }


        for(int i = 0; i < this->n; ++i)
        {
            for(int j = 0; j < this->n; ++j)
            {
                if(i == j)
                {
                    inRange[i][j] = 1;
                }
                else
                {
                    if(bomb1ContainsBomb2(bombs[i], bombs[j], r_2s[i]))
                        inRange[i][j] = 1;
                    else
                        inRange[i][j] = 0;
                }
            }
        }
        int ans = 0;

        for(int i = 0; i < this->n; ++i)
        {
            this->visit = vector<char> (this->n, 0);            
            int&& count = this->DFS(inRange, i);
            if(count > ans)
                ans = count;
        }

        return ans;
    }
};


class Solution2 
{
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    }

    long long pow2(int num)
    {
        return static_cast<long long>(num) * num;
    }

    bool bomb1ContainsBomb2(vector<int>& bomb1, vector<int>& bomb2, long long& r_2)
    {
        long long&& x_2 = this->pow2(bomb1[0] - bomb2[0]);
        long long&& y_2 = this->pow2(bomb1[1] - bomb2[1]);
        return x_2 + y_2 <= r_2;
    }


    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int n = bombs.size();
        int ans = 1;
        vector<vector<int>> inRange (n, vector<int>(n, -1));
        //define inRange[m][n], 1: n in m's range, 0: not in, -1: not calculated
        sort(bombs.begin(), bombs.end(), Solution2::cmp);
        vector<long long> r_2s (n);
        for(int i = 0; i < n ; ++i)
        {
            r_2s[i] = static_cast<long long>(bombs[i][2]) * bombs[i][2];
        }


        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i == j)
                {
                    inRange[i][j] = 1;
                }
                else
                {
                    if(inRange[j][i] == 1)
                    {
                        inRange[i][j] = 1;
                    }
                    else
                    {
                        if(bomb1ContainsBomb2(bombs[i], bombs[j], r_2s[i]))
                            inRange[i][j] = 1;
                        else
                            inRange[i][j] = 0;
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                for(int k = 0; k < n; ++k)
                {
                    if(inRange[i][j] && inRange[j][k])
                        inRange[i][k] = 1;
                }
            }
        }

        for(auto& res: inRange)
        {
            int&& count = accumulate(res.begin(), res.end(), 0);           
            if(count > ans)
                ans = count;
        }

        return ans;
    }
};