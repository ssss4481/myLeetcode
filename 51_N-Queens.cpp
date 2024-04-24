#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> ret;

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> n_queens(n, std::string(n, '.'));
        std::vector<int> rows(n, -1);
        place_queen(n_queens, rows, n, 0);
        return this->ret;
    }

    void place_queen(std::vector<std::string>& n_queens, std::vector<int>& rows, const int n, int current_col){
        if(current_col == n){
            this->ret.push_back(n_queens);
            return;
        }

        for(int r = 0; r < n; ++r){
            if(rows[r] != -1){
                continue;
            }
            bool conflict = false;
            for(int prev_r = 0; prev_r < n; ++prev_r){
                if(rows[prev_r] != -1){
                    if(rows[prev_r] - current_col == r - prev_r || rows[prev_r] - current_col == prev_r - r){
                        conflict = true;
                        break;
                    }
                }
            }
            if(conflict){
                continue;
            }
            rows[r] = current_col;
            n_queens[r][current_col] = 'Q';
            place_queen(n_queens, rows, n, current_col+1);
            n_queens[r][current_col] = '.';
            rows[r] = -1;
        }
    }
};