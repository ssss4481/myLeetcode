#include <vector>
#include <string>
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
    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word.front() && DFS(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool DFS(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int c)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||  board[i][j] != word[c])
        {
            return false;
        }

        if(c == static_cast<int>(word.size()) - 1)
        {
            return true;
        }
        ++c;
        board[i][j] = '1';
        bool res = DFS(board, word, i+1, j, c) || DFS(board, word, i-1, j, c) || DFS(board, word, i, j+1, c) || DFS(board, word, i, j-1, c);
        board[i][j] = word[c-1];
        return res;
    }
};