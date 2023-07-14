#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    int n;
    vector<char> visit;//0 is not visited , 1 is visited but not end, 2 is visited and end.
    vector<char> isSafe;//0 unknown, 1 safe, 2 unsafe.

public: 
    void safeDFS(int node, vector<vector<int>>& graph)
    {  
        this->visit[node] = 1;

        for(int& nextNode: graph[node])
        {
            if(this->visit[nextNode] == 0)
            {
                safeDFS(nextNode, graph);
            }

            if(this->visit[nextNode] == 1)
            {
                this->isSafe[node] = 2;
            }
            else if(this->isSafe[nextNode] == 2)
            {
                this->isSafe[node] = 2;
            }            
        }

        this->visit[node] = 2;
        //cout << int(this->isSafe[node]) << " of node:" << node << '\n';
        if(this->isSafe[node] != 2)
        {
            this->isSafe[node] = 1;
        }
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        this->n = graph.size();
        this->visit = vector<char> (n, 0);
        this->isSafe = vector<char> (n, 0);      
        vector<int> ret;
        
        for(int i = 0; i < n; ++i)
        {
            if(visit[i] != 2)
            {
                safeDFS(i, graph);
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(this->isSafe[i] == 1)
            {
                ret.push_back(i);
            }
        }

        return ret;
    }
};



class Solution2 
{
public: 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> ret;
        vector<char> safeFlags(graph.size(), 0);
        bool diff = true;
        while(diff)
        {
            diff = false;
            for(int node = 0; node < graph.size(); ++node)
            {
                if(safeFlags[node])
                {
                    continue;
                }

                if(graph[node].size() == 0 && safeFlags[node] == 0)                
                {
                    diff = true;
                    safeFlags[node] = 1;                    
                    continue;
                }

                bool isSafe = true;
                for(int& nextNode: graph[node])
                {
                    if(safeFlags[nextNode] == 0)
                    {
                        isSafe = false;
                        break;
                    }
                }
                if(isSafe && safeFlags[node] == 0)
                {
                    safeFlags[node] = 1;
                    diff = true;
                }
            }            
        }

        for(int i = 0; i < safeFlags.size(); ++i)
        {
            if(safeFlags[i])
            {
                ret.push_back(i);
            }
        }
        return ret;          
    }
};