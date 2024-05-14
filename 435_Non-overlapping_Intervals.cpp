#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        auto cmp = [](vector<int>& interval1, vector<int>& interval2){
            return interval1.front() < interval2.front();
        };

        sort(intervals.begin(), intervals.end(), cmp);
        int erase_count = 0;
        vector<int> base_interval = {};
        for(auto& interval: intervals){
            if(base_interval.empty() || !overlapping(base_interval, interval)){
                base_interval = interval;
            }else{
                ++erase_count;
                if(interval.back() < base_interval.back()){
                    base_interval = interval;
                }
            }
        }
        return erase_count;
    }
    
    bool overlapping(const vector<int>& interval1, const vector<int>& interval2){

        return !(interval1.front() >= interval2.back() || interval1.back() <= interval2.front());
    }

};

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
