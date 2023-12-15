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
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        std::vector<std::vector<int>> ret (n, std::vector<int>(m));

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ret[j][i] = matrix[i][j];
            }
        }

        return ret;        
    }
};