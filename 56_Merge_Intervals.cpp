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
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
    {
        auto cmp = [](std::vector<int>& a, std::vector<int>& b)
        {
            if(a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];        
        };

        std::sort(intervals.begin(), intervals.end(), cmp);

        std::vector<std::vector<int>> ret;
        ret.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(ret.back()[1] >= intervals[i][0])
            {
                ret.back()[1] = std::max(ret.back()[1], intervals[i][1]);
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};


class Solution1 
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) 
    {
        auto cmp = [](std::vector<int>& a, std::vector<int>& b)
        {
            return a[1] < b[1];            
        };

        auto overlapping = [](std::vector<int>& a, std::vector<int>& b)
        {
            return !(b[0] > a[1] || b[1] < a[0]);
        };

        int beforeSize;
        
        do
        {
            beforeSize = int(intervals.size());
            std::sort(intervals.begin(), intervals.end(), cmp);
            std::vector<std::vector<int>> pass;
            std::vector<int> interval = intervals[0];
            for(auto& p: intervals)
            {
                if(overlapping(interval, p))
                {
                    interval[0] = std::min(p[0], interval[0]);
                    interval[1] = std::max(p[1], interval[1]);
                }
                else
                {
                    pass.push_back(interval);
                    interval = p;
                }
            }
            pass.push_back(interval);           
            intervals = pass;
        }while(beforeSize != int(intervals.size()));
        return intervals;
    }
};