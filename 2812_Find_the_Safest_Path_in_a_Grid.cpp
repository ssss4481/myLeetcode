#include <vector>
#include <queue>
#include <iostream>
static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();
using namespace std;

class Solution {//BFS + greedy
private: 
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        queue<pair<int, int>> Q;
        vector<pair<int, int>> fix;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    Q.push({i, j});
                    fix.push_back({i, j});
                }
            }
        }

        auto update_and_push = [&](int x, int y, int safe){
            if(grid[x][y] == 0){
                grid[x][y] = safe;
                Q.push({x, y});
            }
        };

        //BFS
        int safe = 0;
        while(!Q.empty()){
            ++safe;
            int size = Q.size();
            for(int i = 0; i < size; ++i){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                for(auto& dir: dirs){
                    int next_x = x+dir.front();
                    int next_y = y+dir.back();
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n){
                        continue;
                    }
                    update_and_push(next_x, next_y, safe);
                }
            }
        }

        for(auto& pos: fix){
            grid[pos.first][pos.second] = 0;
        }

        int res = INT_MAX;

        auto cmp = [](const vector<int>& v1, const vector<int>& v2){
            return v1.front() < v2.front();
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> PQ(cmp);
        PQ.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while(!PQ.empty()){
            int safe = PQ.top()[0];
            int x = PQ.top()[1];
            int y = PQ.top()[2];
            PQ.pop();
            res = min(res, safe);
            if(x == m-1 && y == n-1){
                return res;
            }
            for(auto& dir: dirs){
                int next_x = x+dir.front();
                int next_y = y+dir.back();
                if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || grid[next_x][next_y] == -1){
                    continue;
                }
                PQ.push({grid[next_x][next_y], next_x, next_y});
                grid[next_x][next_y] = -1;
            }
        }
        return res;
    }
};

class Solution1 {//BFS + BFS
private: 
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        queue<pair<int, int>> Q;
        vector<pair<int, int>> fix;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    Q.push({i, j});
                    fix.push_back({i, j});
                }
            }
        }

        auto update_and_push = [&](int x, int y, int safe){
            if(grid[x][y] == 0){
                grid[x][y] = safe;
                Q.push({x, y});
            }
        };

        //BFS
        int safe = 0;
        while(!Q.empty()){
            ++safe;
            int size = Q.size();
            for(int i = 0; i < size; ++i){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                for(auto& dir: dirs){
                    int next_x = x+dir.front();
                    int next_y = y+dir.back();
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n){
                        continue;
                    }
                    update_and_push(next_x, next_y, safe);
                }
            }
        }

        for(auto& pos: fix){
            grid[pos.first][pos.second] = 0;
        }

        int lo = 0;
        int hi = min(grid.front().front(), grid.back().back());
        int res = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(BFS(grid, mid, m, n)){
                res = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return res;
    }

    bool BFS(vector<vector<int>> grid, const int threshold, const int m, const int n){
        queue<pair<int, int>>  Q;
        Q.push({0, 0});
        while(!Q.empty()){
            int size = Q.size();
            for(int i = 0; i < size; ++i){
                int x = Q.front().first;
                int y = Q.front().second;
                if(x == m-1 && y == n-1){
                    return true;
                }
                Q.pop();
                for(auto& dir: dirs){
                    int next_x = x+dir.front();
                    int next_y = y+dir.back();
                    if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || grid[next_x][next_y] < threshold){
                        continue;
                    }
                    grid[next_x][next_y] = -1;
                    Q.push({next_x, next_y});
                }
            }
        }
        return false;
    }
};