#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>


class Solution 
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) 
    {
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b)
        {
            return a[1] < b[1];
        };  

        std::sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int k = -50000;
        
        for(auto& interval: intervals)
        {
            if(interval[0] >= k)
            {
                k = interval[1];
            }
            else
            {
                ++count;
            }
        }
        return count;
    }
};


int main(int argc, char const *argv[])
{
    return 0;
}
