#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

struct ToNext{
    int node;
    int cost;
    ToNext(){}
    ToNext(int _neighbor, int _cost): node{_neighbor}, cost{_cost}{}
};

struct ToNextCmp{
    bool operator()(const ToNext& e1, const ToNext& e2){
        return e1.cost > e2.cost;
    }
};

struct Edge{
    int a;
    int b;
    Edge(){};
    Edge(int _a, int _b):a{_a}, b{_b}{}
    bool operator==(const Edge& rhs) const{
        return a == rhs.a && b == rhs.b;
    }
};

struct EdgeHash{
    size_t operator()(const Edge& e) const{
        return hash<int>()(e.a) ^ hash<int>()(e.b);
    }
};

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<ToNext>> adj(n);
        for(auto& edge: edges){
            int& a = edge[0];
            int& b = edge[1];
            int& w = edge[2];
            adj[a].push_back(ToNext(b, w));
            adj[b].push_back(ToNext(a, w));
        }
        vector<int> shortest_cost(n, INT_MAX);
        Dijk(n, adj, shortest_cost);
        vector<bool> res(edges.size(), false);
        if(shortest_cost.back() == INT_MAX){
            return res;
        }
        unordered_set<Edge, EdgeHash> EdgeSet;
        DFS(-1, 0, 0, adj, shortest_cost, EdgeSet);

        for(int i = 0; i < res.size(); ++i){
            int& a = edges[i][0];
            int& b = edges[i][1];
            if(EdgeSet.count(Edge(a, b)) == 1){
                res[i] = true;
            }
        }
        return res;
    }

    void Dijk(int n, vector<vector<ToNext>>& adj, vector<int>& shortest_cost){
        shortest_cost[0] = 0;
        priority_queue<ToNext, vector<ToNext>, ToNextCmp> PQ;
        PQ.push(ToNext(0, 0));
        bool visit[n];
        memset(visit, false, n*sizeof(bool));
        while(!PQ.empty()){
            auto candidate = PQ.top();
            PQ.pop();
            if(visit[candidate.node]){
                continue;
            }
            visit[candidate.node] = true;
            for(auto& next: adj[candidate.node]){
                if(shortest_cost[candidate.node] + next.cost < shortest_cost[next.node]){
                    shortest_cost[next.node] = shortest_cost[candidate.node] + next.cost;
                    PQ.push(ToNext(next.node, shortest_cost[next.node]));
                }
            }
        }
    }

    bool DFS(int prev, int cur, int cur_cost, vector<vector<ToNext>>& adj, vector<int>& shortest_cost, unordered_set<Edge, EdgeHash>& EdgeSet){
        if(cur_cost > shortest_cost[cur]){
            return false;
        }

        if(cur == adj.size()-1 && cur_cost == shortest_cost[cur]){
            return true;
        }
        bool flag = false;
        for(auto& next: adj[cur]){
            if(cur != prev && DFS(cur, next.node, cur_cost+next.cost, adj, shortest_cost, EdgeSet)){
                EdgeSet.insert(Edge(cur, next.node));
                EdgeSet.insert(Edge(next.node, cur));
                flag = true;
            }
        }
        return flag;
    }


};