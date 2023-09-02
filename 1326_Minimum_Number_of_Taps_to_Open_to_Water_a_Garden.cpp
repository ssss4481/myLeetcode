#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution 
{
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> maxReach(n+1);
        for(int i = 0; i < n+1; ++i)
        {
            int left = max(0, i-ranges[i]);
            int right = min(i+ranges[i], n);

            maxReach[left] = max(maxReach[left], right);
        }
        int count = 0;
        int currEnd = 0;
        int reachableEnd = 0;
        for(int start = 0; start < n+1; ++start)
        {
            if(start > reachableEnd)
            {
                return -1;
            }

            if(start > currEnd)
            {
                ++count;               
                currEnd = reachableEnd;
            }

            reachableEnd = max(reachableEnd, maxReach[start]);
        }
        return count;        
    }
};