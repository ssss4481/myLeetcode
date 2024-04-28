#include <vector>

class Solution {
public:
    bool canMakeSquare(std::vector<std::vector<char>>& grid) {
        int Bcount[2][2];
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                if(grid[i][j] == 'B'){
                    ++Bcount[i][j];
                }
                if(grid[i+1][j] == 'B'){
                    ++Bcount[i][j];
                }
                if(grid[i][j+1] == 'B'){
                    ++Bcount[i][j];
                }
                if(grid[i+1][j+1] == 'B'){
                    ++Bcount[i][j];
                }    
                if(Bcount[i][j] != 2){
                    return true;
                }
            }
        }

        return false;
    }
};