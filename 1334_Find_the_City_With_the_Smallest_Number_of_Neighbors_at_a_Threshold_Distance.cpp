#include <iostream>
#include <vector>

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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for(auto& edge: edges){
            int& from = edge[0];
            int& to = edge[1];
            int& w = edge[2];
            distance[from][to] = w;
            distance[to][from] = w;
        }

        for(int i = 0; i < n; ++i){
            distance[i][i] = 0;
        }

        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if(distance[i][j]-distance[i][k] > distance[k][j]){
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }

        int city = 0;
        int neighbors = n;

        for(int i = 0; i < n; ++i){
            int count = 0;
            
            for(int j = 0; j < n; ++j){
                if(i != j && distance[i][j] <= distanceThreshold){
                    ++count;
                }
            }

            if(count <= neighbors){
                neighbors = count;
                city = i;
            }
        }

        return city;
    }
};