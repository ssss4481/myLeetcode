#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].emplace_back(edge[1]);
        }
        vector<vector<int>> ancestors(n);
        for(int i = 0; i < n; ++i){
            DFS(i, i, adj, ancestors);
        }
        return ancestors;
    }

    void DFS(int ancestor, int current, vector<vector<int>>& adj, vector<vector<int>>& ancestors){
        for(auto& next: adj[current]){
            if(ancestors[next].empty() || ancestors[next].back() != ancestor){
                ancestors[next].emplace_back(ancestor);
                DFS(ancestor, next, adj, ancestors);
            }
        }
    }
};

class Solution1 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> revadj(n);
        vector<int> inorder(n, 0);

        for(auto& edge:edges){
            revadj[edge[1]].push_back(edge[0]);
            ++inorder[edge[0]];
        }


        vector<unordered_set<int>> ancestors(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(inorder[i] == 0){
                DFS(i, visited, revadj, ancestors);
            }
        }
        vector<vector<int>> result(n);
        for(int i = 0; i < n; ++i){
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            sort(result[i].begin(), result[i].end());
        }
        return result;
        
    }

    void DFS(int current, vector<bool>& visited, vector<vector<int>>& adj, vector<unordered_set<int>>& ancestors){
        for(auto& next: adj[current]){
            if(!visited[next]){
                visited[next] = true;
                DFS(next, visited, adj, ancestors);
            }
            for(auto& ancestor: ancestors[next]){
                ancestors[current].insert(ancestor);
            }
            ancestors[current].insert(next);
        }
    }
};