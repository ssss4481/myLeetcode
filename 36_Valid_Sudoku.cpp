#include <vector>
#include <iostream>
static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) 
    {
        const int boardSize = 9;
        const int blockSize = 3;
        bool rowHas[boardSize][boardSize] = {false};
        bool colHas[boardSize][boardSize] = {false};
        bool blockHas[boardSize][boardSize] = {false};

        auto confict = [&] (int i, int j, int num)
        {
            return rowHas[i][num-1] || colHas[j][num-1] || blockHas[i/blockSize*blockSize + j/blockSize][num-1];
        };

        auto place = [&] (int i, int j, int num)
        {
            rowHas[i][num-1] = true;
            colHas[j][num-1] = true;
            blockHas[i/blockSize*blockSize + j/blockSize][num-1] = true;
        };

        for(int i = 0; i < boardSize; ++i)
        {
            for(int j = 0; j < boardSize; ++j)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }

                if(confict(i, j, int(board[i][j]-'0')))
                {
                    return false;
                }
                place(i, j, int(board[i][j]-'0'));
            }
        }
        return true;
    }
};