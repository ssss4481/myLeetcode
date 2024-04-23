#include <iostream>
#include <vector>
#include <queue>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        int order[n];
        memset(order, 0, n*sizeof(int));

        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            ++order[edge[0]];
            ++order[edge[1]];
        }

        std::queue<int> Q1;

        for(int i = 0; i < n; ++i){
            if(order[i] <= 1){
                Q1.push(i);
            }
        }

        int valid_count = n;
        while(valid_count > 2){
            std::queue<int> Q2;
            valid_count -= Q1.size();
            while(!Q1.empty()){
                int node = Q1.front();
                Q1.pop();
                for(auto& next: adj[node]){
                    if(--order[next] == 1){
                        Q2.push(next);
                    }
                }
            }
            Q1.swap(Q2);
        }

        std::vector<int> ret;
        while(!Q1.empty()){
            ret.push_back(Q1.front());
            Q1.pop();
        }

        return ret;
    }
};