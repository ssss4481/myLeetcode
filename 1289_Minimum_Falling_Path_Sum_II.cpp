#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef struct my_data{
    int val;
    int col;
    my_data(){}
    my_data(int _val, int _col){
        val = _val;
        col = _col;    
    }

}my_data;

struct data_cmp{
    bool operator()(const my_data& d1, const my_data& d2){
        return d1.val > d2.val;
    }
};


class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& grid) {
        if(grid.size() == 1){
            return grid[0][0];
        }
        const int n = grid.size();

        for(int i = n-2; i >= 0; --i){
            std::vector<int>& dp = grid[i];
            std::vector<my_data> row(n);
            for(int j = 0; j < n; ++j){
                row[j].val = grid[i+1][j];
                row[j].col = j;
            }
            std::make_heap(row.begin(), row.end(), data_cmp());
            my_data min1_d = row.front();
            std::pop_heap(row.begin(), row.end(), data_cmp());
            my_data& min2_d = row.front();
            
            for(int j = 0; j < n; ++j){
                if(j != min1_d.col){
                    dp[j] += min1_d.val;
                }else{
                    dp[j] += min2_d.val;
                }
            }
        }

        return (*std::min_element(grid[0].begin(), grid[0].end()));
    }
};