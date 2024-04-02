#include <vector>

class Solution 
{
public:
    void rotate(std::vector<std::vector<int>>& matrix) 
    {
        int delta {static_cast<int>(matrix.size())-1};
        int start = 0;

        while(delta >= 1)
        {
            const int end = start+delta;
            int LU[2] = {start, start};
            int RU[2] = {start, end};
            int LD[2] = {end, start};
            int RD[2] = {end, end};
            for(int i = 1; i <= delta; ++i)
            {
                int temp = matrix[LU[0]][LU[1]];
                matrix[LU[0]][LU[1]++] = matrix[LD[0]][LD[1]];
                matrix[LD[0]--][LD[1]] = matrix[RD[0]][RD[1]];
                matrix[RD[0]][RD[1]--] = matrix[RU[0]][RU[1]];
                matrix[RU[0]++][RU[1]] = temp;
            }
            delta -= 2;
            ++start;
        }
    }
};