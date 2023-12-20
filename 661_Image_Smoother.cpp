#include <vector>
#include <algorithm>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) 
    {
        const int m = img.size();
        const int n = img[0].size();

        std::vector<std::vector<int>> ret(m, std::vector<int>(n));

        auto getVal = [&](int i, int j)
        {
            if(i < 0 || i >= m || j < 0 || j >= n)
            {
                return std::make_pair(0, 0);
            }
            else
            {
                return std::make_pair(img[i][j], 1);
            }
        };

        auto convolution = [&](int& ci, int& cj)
        {
            int sum = 0;
            int count = 0;

            for(int i = -1; i <= 1; ++i)
            {
                for(int j = -1; j <= 1; ++j)
                {
                    auto res = getVal(ci+i, cj+j);
                    sum += res.first;
                    count += res.second;
                }
            }
            return sum/count;
        };
        for(int i = 0; i < m; ++i)
        {   
            for(int j = 0; j < n; ++j)
            {
                ret[i][j] = convolution(i, j);
            }
        }
        return ret;        
    }
};