#include <vector>
#include <numeric>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maximumDetonation(std::vector<std::vector<int>>& bombs) {
        const int n = bombs.size();
        std::vector<long long> r_square(n);

        for(int i = 0; i < n; ++i){
            r_square[i] = static_cast<long long>(bombs[i][2]) * bombs[i][2];
        }

        auto distance_square = [](const std::vector<int>& b1, const std::vector<int>& b2){
            long long dx = b1[0]-b2[0];
            long long dy = b1[1]-b2[1];
            return dx*dx + dy*dy;
        };

        std::vector<std::vector<int>> adj(n);

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                long long d_s = distance_square(bombs[i], bombs[j]);
                if(d_s <= r_square[i]){
                    adj[i].push_back(j);
                }
                if(d_s <= r_square[j]){
                    adj[j].push_back(i);
                }                
            }
        }

        bool visit[n];
        int best_record = -1;
        for(int i = 0; i < n; ++i){
            int sum = 0;
            memset(visit, false, n*sizeof(bool));
            DFS(adj, visit, i, sum);
            best_record = std::max(best_record, sum);
        }
        return best_record;
    }

    void DFS(std::vector<std::vector<int>>& adj, bool visit[], int current, int& sum){
        if(visit[current] == true){
            return;
        }
        ++sum;
        visit[current] = true;
        for(auto& next: adj[current]){
            DFS(adj, visit, next, sum);
        }
    }
};