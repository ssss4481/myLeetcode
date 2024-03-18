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
    int findMinArrowShots(std::vector<std::vector<int>>& points) 
    {
        auto cmp = [](std::vector<int>& a, std::vector<int>& b)
        {
            return a[1] < b[1];
        };
        std::sort(points.begin(), points.end(), cmp);
        int i = 0;
        int count = 0;
        while(i < points.size())
        {
            int aim = points[i][1];
            ++i;
            ++count;
            while (i < points.size() && aim >= points[i][0])
            {
                ++i;
            }          
        }
        return count;          
    }
};