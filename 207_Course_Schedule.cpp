#include <vector>

using namespace std;
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& edge: prerequisites){
            int& a = edge[0];
            int& b = edge[1];
            adj[b].push_back(a);
        }

        char visited[numCourses];
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == 0){
                if(!DFS_has_circle(i, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }

    bool DFS_has_circle(int cur, vector<vector<int>>& adj, char visited[]){
        if(visited[cur] == 1){
            return false;
        }
        if(visited[cur] == 2){
            return true;
        }
        visited[cur] = 1;
        for(auto& next: adj[cur]){
            if(!DFS_has_circle(next, adj, visited)){
                return false;
            }
        }
        visited[cur] = 2;
        return true;
    }
};



class Solution1
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