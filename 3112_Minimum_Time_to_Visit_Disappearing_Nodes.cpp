#include <vector>
#include <queue>

typedef std::pair<int, int> node_and_length;
typedef std::pair<int, int> node_and_key;

class Solution {
public:
    std::vector<int> minimumTime(int n, std::vector<std::vector<int>>& edges, std::vector<int>& disappear) {
        std::vector<std::vector<node_and_length>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        return Dijk(n, adj, disappear);
    }

    std::vector<int> Dijk(int n, std::vector<std::vector<node_and_length>>& adj, std::vector<int>& disappear){
        std::vector<int> answer(n, INT_MAX);
        answer[0] = 0;
        bool visit[n];
        memset(visit, false, n*sizeof(bool));

        auto cmp = [](const node_and_key& a, const node_and_key& b){
            return a.second > b.second;
        };

        std::priority_queue<node_and_key, std::vector<node_and_key>, decltype(cmp)> PQ(cmp);        
        PQ.push({0, 0});
        while(!PQ.empty()){
            int start = PQ.top().first;
            if(!visit[start]){
                visit[start] = true;
                for(auto& next_and_length: adj[start]){
                    int next = next_and_length.first;
                    int length = next_and_length.second;
                    if(answer[start] + length < answer[next]){
                        if(answer[start] + length < disappear[next]){
                            answer[next] = answer[start] + length;
                            PQ.push({next, answer[next]});
                        }
                    }
                }
            }
            PQ.pop();
        }

        for(auto& ans: answer){
            if(ans == INT_MAX){
                ans = -1;
            }
        }
        return answer;
    }
};