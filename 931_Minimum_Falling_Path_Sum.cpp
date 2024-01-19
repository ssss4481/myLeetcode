#include <vector>
#include <algorithm>
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
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) 
    {
        auto minOfThree = [&matrix](int row, int col)
        {
            int left = std::max(col-1, 0);
            int right = std::min(col+1, int(matrix[0].size())-1);
            return *std::min_element(matrix[row].begin()+left, matrix[row].begin()+right+1);
        };

        const int m = matrix.size();
        const int n = m;

        for(int i = m-1; i > 0; --i)
        {
            for(int j = 0; j < n; ++j)
            {               
                matrix[i-1][j] += minOfThree(i, j);
            }
        }
        return *std::min_element(matrix[0].begin(), matrix[0].end());        
    }
};