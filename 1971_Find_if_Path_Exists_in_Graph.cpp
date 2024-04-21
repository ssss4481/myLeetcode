#include <vector>
#include <string.h>
#include <iostream>
#include <unordered_map>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::vector<std::vector<int>> adj;

    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        this->adj = std::vector<std::vector<int>>(n);
        
        for(auto& edge: edges){
            this->adj[edge[0]].push_back(edge[1]);
            this->adj[edge[1]].push_back(edge[0]);
        }

        bool visit[n];
        memset(visit, 0, n*sizeof(bool));
        return DFS(visit ,source, destination);
    }

    bool DFS(bool visit[], int current, const int destination){
        if(visit[current] == true){
            return false;
        }
        visit[current] = true;

        if(current == destination){
            return true;
        }
        for(auto& next: this->adj[current]){
            if(DFS(visit, next, destination)){
                return true;
            }
        }
        return false;
    }
};