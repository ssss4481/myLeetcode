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

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int lo = 0;
        int hi = people.size()-1;
        
        sort(people.begin(), people.end());

        while(lo <= hi){
            ++count;
            int capacity = 2;
            int cur_limit = limit;
            if(cur_limit >= people[hi]){
                cur_limit -= people[hi];
                --hi;
                --capacity;
            }
            if(lo <= hi && cur_limit >= people[hi]){
                cur_limit -= people[hi];
                --hi;
                --capacity;
            }            
            if(lo <= hi && capacity > 0 && cur_limit >= people[lo]){
                ++lo;
            }
        }

        return count;
    }
};