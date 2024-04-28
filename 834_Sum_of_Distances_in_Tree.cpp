#include <vector>
#include <climits>
#include <numeric>
#include <cstring>


class Solution {
public:
    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int nodeCount[n];
        std::vector<int> distanceSum(n, 0);
        memset(nodeCount, 0, sizeof(nodeCount));
        DFS_for_tree_structure(0, adj, -1, nodeCount, distanceSum);
        DFS_for_result(0, adj, -1, nodeCount, distanceSum);
        return distanceSum;
    }

    void DFS_for_tree_structure(int current, std::vector<std::vector<int>>& adj, int prev, int nodeCount[], std::vector<int>& distanceSum){
        for(auto& next: adj[current]){
            if(next != prev){
                DFS_for_tree_structure(next, adj, current, nodeCount, distanceSum);
                nodeCount[current] += nodeCount[next];
                distanceSum[current] += distanceSum[next] + nodeCount[next];
            }
        }
        ++nodeCount[current];
    }

    void DFS_for_result(int current, std::vector<std::vector<int>>& adj, int prev, int nodeCount[], std::vector<int>& distanceSum){
        for(auto& next: adj[current]){
            if(next != prev){
                distanceSum[next] = distanceSum[current] - nodeCount[next] + distanceSum.size() - nodeCount[next];
                DFS_for_result(next, adj, current, nodeCount, distanceSum);
            }
        }
    }
};
















class Solution1 {//TLE
public:
    std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<int> distance(n, 0);
        bool visit[n];
        for(int i = 0; i < n; ++i){
            memset(visit, false, sizeof(visit));
            DFS(0, i, visit, adj, distance);
        }
 
        return distance;
    }

    void DFS(int depth, int current, bool visit[], const std::vector<std::vector<int>>& adj, std::vector<int>& distance){
        if(visit[current]){
            return;
        }
        visit[current] = true;
        distance[current] += depth;

        for(auto& next: adj[current]){
            DFS(depth+1, next, visit, adj, distance);
        }
    }
};