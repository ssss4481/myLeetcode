#include <vector>
#include <queue>
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
    int shortestBridge(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        queue<pair<int, int>>Q;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    DFS(grid, Q, i, j, m, n);
                    return BFS(grid, Q, m, n);
                }
            }
        }

        return -1;        
    }

    void DFS(vector<vector<int>>& grid, queue<pair<int, int>>& Q, int i, int j, const int m, const int n){
        if(grid[i][j] == 0){
            return;
        }
        if(grid[i][j] == 2){
            return;
        }
        grid[i][j] = 2;
        if(i + 1 < m){
            DFS(grid, Q, i+1, j, m, n);
        }
        if(i > 0){
            DFS(grid, Q, i-1, j, m, n);
        }
        if(j + 1 < n){
            DFS(grid, Q, i, j+1, m, n);
        }
        if(j > 0){
            DFS(grid, Q, i, j-1, m, n);
        }        
        Q.push({i, j});
    }

    int BFS(vector<vector<int>>& grid, queue<pair<int, int>>& Q, const int m, const int n){
        int distance = 0;
        auto check_and_push = [&](int i, int j){
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1){
                return -1;
            }
            if(grid[i][j] == 1){
                return 1;
            }
            if(grid[i][j] == 0){
                grid[i][j] = -1;
                Q.push({i, j});
            }
            return -1;
        };

        while(!Q.empty()){
            int k = Q.size();
            for(int t = 1; t <= k; ++t){
                int i = Q.front().first;
                int j = Q.front().second;
                Q.pop();
                if(check_and_push(i+1, j) == 1){
                    return distance;
                }
                if(check_and_push(i-1, j) == 1){
                    return distance;
                }
                if(check_and_push(i, j+1) == 1){
                    return distance;
                }
                if(check_and_push(i, j-1) == 1){
                    return distance;
                }                                                
            }
            ++distance;
        }
        return INT_MAX;
    }
};