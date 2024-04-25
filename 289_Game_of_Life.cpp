#include <vector>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

#define TURN_ON -1
#define TURN_OFF 2

class Solution {//in-place
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        auto count_of_live_neighbors = [&](int i, int j){
            
            auto valid_index = [&](int x, int y){
                return !(x < 0 || y < 0 || x >= m || y >= n);
            };

            int count = 0;
            
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    if(dx == 0 && dy == 0){
                        continue;
                    }
                    if(valid_index(i+dx, j+dy)){
                        if(board[i+dx][j+dy] > 0){
                            ++count;
                        }
                    }
                }
            }
            return count;
        };


        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int live_neighbor = count_of_live_neighbors(i, j);
                if(board[i][j] > 0){
                    if(live_neighbor < 2 || live_neighbor > 3){
                        board[i][j] = TURN_OFF;
                    }
                }else{
                    if(live_neighbor  == 3){
                        board[i][j] = TURN_ON;
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == TURN_ON){
                    board[i][j] = 1;
                }else if(board[i][j] == TURN_OFF){
                    board[i][j] = 0;
                }
            }
        }
        
    }
};