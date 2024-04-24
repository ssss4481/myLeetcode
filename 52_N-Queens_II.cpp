#include <vector>
#include <cmath>

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<int> rows(n, -1);
        placeQueen(n, count, rows, 0);
        return count;
    }

    void placeQueen(const int n, int& count, std::vector<int>& rows, int current_col){
        if(current_col == n){
            ++count;
            return;
        }
        for(int r = 0; r < n; ++r){
            if(rows[r] != -1){
                continue;
            }
            bool conflict = false;
            for(int prev_r = 0; prev_r < n; ++prev_r){
                if(rows[prev_r] != -1){
                    if(std::abs(prev_r - r) == current_col - rows[prev_r]){
                        conflict = true;
                        break;
                    }
                }
            }
            if(conflict){
                continue;
            }
            rows[r] = current_col;
            placeQueen(n, count, rows, current_col+1);
            rows[r] = -1;
        }
    }
};