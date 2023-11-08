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
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int dx = std::abs(fx-sx);
        int dy = std::abs(fy-sy);
        int shortestTime = std::max(dx, dy);
        if(shortestTime == 0)
        {
            return t > 1 || t == 0;
        }
        return shortestTime <= t;
    }
};