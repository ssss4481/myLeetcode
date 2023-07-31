#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1] < b[1];
}  

class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);

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
