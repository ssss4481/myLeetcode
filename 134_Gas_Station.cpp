#include <vector>
#include <numeric>
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
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) 
    {
        if(std::accumulate(gas.begin(), gas.end(), 0LL) < std::accumulate(cost.begin(), cost.end(), 0LL))
        {
            return -1;
        }

        int ans = 0;
        int sum = 0;

        
        for(int i = 0; i < gas.size(); ++i)
        {
            if(sum < 0)
            {
                ans = i;
                sum = 0;
            }            
            sum += gas[i]-cost[i];
        }
        return sum >= 0 ? ans : -1;
    }
};


