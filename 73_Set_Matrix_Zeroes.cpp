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
    void setZeroes(std::vector<std::vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if(i == 0)
                    {
                        firstRowZero = true;
                    }
                    if(j == 0)
                    {
                        firstColZero = true;
                    }
                }
            }
        }

        for(int j = 1; j < n; ++j)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 1; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < m; ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColZero)
        {
            for(int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }

        if(firstRowZero)
        {
            for(int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }            
        }
    }
};