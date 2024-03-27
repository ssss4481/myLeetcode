#include <vector>
#include <string>
#include <iostream>

#define BLOCKSIZE 3
#define BOARDSIZE 9
#define CELLS BOARDSIZE*BOARDSIZE


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Sudoku
{
private:
    std::vector<std::vector<bool>> rowHas;
    std::vector<std::vector<bool>> colHas;
    std::vector<std::vector<bool>> blockHas;
    std::vector<std::vector<char>> ans;


public:
    Sudoku(std::vector<std::vector<char>>& initState)
    {
        this->rowHas = this->colHas = this->blockHas = std::vector<std::vector<bool>> (BOARDSIZE, std::vector<bool>(BOARDSIZE, false));
        this->ans = std::move(initState);
        for(int i = 0; i < BOARDSIZE; ++i)
        {
            for(int j = 0; j < BOARDSIZE; ++j)
            {
                if(this->ans[i][j] != '.')
                {
                    place(i, j, int(this->ans[i][j]-'0'));
                }
            }
        }
    }

    bool solve(int level)
    {
        if(level == CELLS)
        {
            return true;
        }
        int row = level / BOARDSIZE;
        int col = level % BOARDSIZE;       

        if(this->ans[row][col] != '.')
        {
            return solve(level+1);
        }

        for(int n = 1; n <= 9; ++n)
        {
            if(!this->confict(row, col, n))
            {
                place(row, col, n);
                if(solve(level+1))
                {
                    return true;
                }
                remove(row, col, n);
            }
        }
        return false;
    }


    bool confict(int i, int j, int num)
    {
        return this->rowHas[i][num-1] || this->colHas[j][num-1] || this->blockHas[i/BLOCKSIZE*BLOCKSIZE + j/BLOCKSIZE][num-1];
    }

    void place(int i, int j, int num)
    {
        this->setCell(i, j, num, true);
    }
    
    void remove(int i, int j, int num)
    {
        this->setCell(i, j, num, false);
    }

    void setCell(int i, int j, int num, bool value)
    {
        this->rowHas[i][num-1] = value; 
        this->colHas[j][num-1] = value;
        this->blockHas[i/BLOCKSIZE*BLOCKSIZE + j/BLOCKSIZE][num-1] = value;   

        if(value)
        {
            this->ans[i][j] = std::to_string(num)[0];
        }
        else
        {
            this->ans[i][j] = '.';
        }
    }

    std::vector<std::vector<char>> getAns()
    {
        return std::move(this->ans);
    }    

    void print()
    {
        for(auto& row: this->ans)
        {
            for(auto& c: row)
            {
                std::cout << c << ' ';
            }
            std::cout << '\n';
        }
    }

};


class Solution 
{
public:
    void solveSudoku(std::vector<std::vector<char>>& board) 
    {
        Sudoku s = Sudoku(board);
        s.solve(0);
        board = s.getAns();
    }
};