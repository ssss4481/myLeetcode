#include <vector>
#include <string.h>

using namespace std;


class Solution 
{
public:
    vector<vector<int>> adj;

    void DFS(int current, const int& n, bool visited[])
    {
        visited[current] = true;
        for(int& vertex: this->adj[current])
        {
            if(!visited[vertex])
                this->DFS(vertex, n, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        const int n = isConnected.size();
        bool visited[n];
        memset(visited, 0, n*sizeof(bool));

        this->adj = vector<vector<int>> (n, vector<int>(0));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(isConnected[i][j])
                {
                    this->adj[i].push_back(j);
                    this->adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                this->DFS(i, n, visited);
                ++count;
            }
        }
        return count;       
    }
};


class Solution2
{
public:
    void DFS(int current, const int& n, bool visited[], vector<vector<int>>& isConnected)
    {
        visited[current] = true;
        for(int i = 0; i < n; ++i)
        {
            if(isConnected[current][i] && !visited[i])
                DFS(i, n, visited, isConnected);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        const int n = isConnected.size();
        bool visited[n];
        memset(visited, 0, n*sizeof(bool));

        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(!visited[i])
            {
                this->DFS(i, n, visited, isConnected);
                ++count;
            }
        }
        return count;       
    }
};