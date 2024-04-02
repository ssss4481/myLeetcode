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
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        const int cells = m*n;
        
        std::vector<int> ret(cells);
        int putIdx = 0;
        int i = 0;
        int j = 0;

        if(m == 1)
        {
            while(putIdx < cells)
            {
                ret[putIdx++] = matrix[0][j++];
            }
            return ret;
        }

        if(n == 1)
        {
            while(putIdx < cells)
            {
                ret[putIdx++] = matrix[i++][0];
            }
            return ret;
        }

        int steps[4] = {n-1, m-1, n-1, m-1};
        const int upDown[4] = {0, 1, 0, -1};
        const int leftRight[4] = {1, 0, -1, 0};
        int state = 0;

        while(putIdx < cells)
        {
            for(int k = 1; k <= steps[state]; ++k)
            {
                ret[putIdx++] = matrix[i][j];
                i += upDown[state];
                j += leftRight[state];
            }
            if(state == 3)
            {
                ++i;
                ++j;
            }
            steps[state] -= 2;
            state = (state+1) % 4;
            if(steps[state] == 0 && putIdx < cells)
            {
                ret[putIdx++] = matrix[i++][j];
                while(putIdx < cells)
                {
                    ret[putIdx++] = matrix[i++][j];
                }
            }
        }
        return ret;
    }
};