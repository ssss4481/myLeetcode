#include <vector>

using namespace std;

class Solution 
{
private:
    vector<vector<int>> adj;
    vector<char> visit;
public:
    bool DFS(int current)
    {
        if(visit[current] == 1)
        {
            return false;
        }

        if(visit[current] == 2)
        {
            return true;
        }        

        this->visit[current] = 1;

        for(auto& nextNode: adj[current])
        {
            if(!DFS(nextNode))
            {
                return false;                
            }
        }

        this->visit[current] = 2;

        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        this->visit = vector<char> (numCourses, 0);
        this->adj = vector<vector<int>>(numCourses, vector<int>(0));
        for(auto& edge: prerequisites)
        {
            this->adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(!DFS(i))
            {
                return false;
            }
        }
        
        return true;
    }
};