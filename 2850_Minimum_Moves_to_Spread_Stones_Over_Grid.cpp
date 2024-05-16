#include <iostream>
#include <vector>
#include <numeric>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
private:
    int col_count;

public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> targets;
        vector<int> sources;
        col_count = grid[0].size();

        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < col_count; ++j){
                if(grid[i][j] == 0){
                    targets.push_back(col_count*i + j);
                }else if(grid[i][j] > 1){
                    sources.push_back(col_count*i + j);
                }
            }
        }

        if(targets.empty()){
            return 0;
        }


        auto distance = [&](int i, int j){
            return abs((i%col_count) - (j%col_count)) + abs((i/col_count) - (j/col_count));
        };

        vector<vector<int>> cost(sources.size(), vector<int>(targets.size(), 0));

        for(int i = 0; i < sources.size(); ++i){
            for(int j = 0; j < targets.size(); ++j){
                cost[i][j] = distance(sources[i], targets[j]);
            }
        }

        vector<int> permutation(targets.size());
        iota(permutation.begin(), permutation.end(), 0);
        int ans = INT_MAX;

        backtrack(cost, permutation, 0, sources, grid, ans);
        return ans;
    }

    void backtrack(vector<vector<int>>& cost, vector<int>& permutation, int i, const vector<int>& sources, const vector<vector<int>>& grid, int& ans){
        if(i == permutation.size()){
            int quota = 0;
            int s = -1;
            int move = 0;
            for(int k = 0; k < permutation.size(); ++k){
                if(quota == 0){
                    ++s;
                    quota = get_value(grid, sources[s])-1;
                }
                move += cost[s][permutation[k]];
                --quota;
            }
            ans = min(ans, move);
            return;
        }

        for(int j = i; j < permutation.size(); ++j){
            swap(permutation[i], permutation[j]);
            backtrack(cost, permutation, i+1, sources, grid, ans);
            swap(permutation[i], permutation[j]);
        }
    }

    int get_value(const vector<vector<int>>& grid, int pos){
        return grid[pos/col_count][pos%col_count];
    }
};