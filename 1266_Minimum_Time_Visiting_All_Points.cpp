#include <vector>
#include <algorithm>

class Solution 
{
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points)     
    {
        int ret = 0;
        for(int i = 1; i < points.size(); ++i)
        {
            auto maxDiff = std::max(std::abs(points[i][0]-points[i-1][0]), std::abs(points[i][1]-points[i-1][1]));
            ret += maxDiff;
        }
        return ret;        
    }
};