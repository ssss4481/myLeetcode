#include <vector>


class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        std::vector<std::vector<char>> visit(m, std::vector<char>(n, 0));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] != 'X' && visit[i][j] == 0){
                    if(!reserved(i, j, visit, board, m, n)){
                        flip(i, j, board, m, n);
                    }
                }
            }
        }
    }
    bool reserved(int x, int y, std::vector<std::vector<char>>& visit, std::vector<std::vector<char>>& board, const int m, const int n){
        if(x < 0 || x >= m || y < 0 || y >= n){
            return true;
        }
        if(visit[x][y] == 1 || board[x][y] == 'X'){
            return false;
        }
        visit[x][y] = 1;
        bool res = false;
        if(reserved(x+1, y, visit, board, m, n)){
            res = true;
        }
        if(reserved(x-1, y, visit, board, m, n)){
            res = true;
        }
        if(reserved(x, y+1, visit, board, m, n)){
            res = true;
        }
        if(reserved(x, y-1, visit, board, m, n)){
            res = true;
        }
        return res;                        
    }

    void flip(int x, int y, std::vector<std::vector<char>>& board, const int m, const int n){
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == 'X'){
            return;
        }
        board[x][y] = 'X';
        flip(x+1, y, board, m, n);
        flip(x-1, y, board, m, n);
        flip(x, y+1, board, m, n);
        flip(x, y-1, board, m, n);
    }



};