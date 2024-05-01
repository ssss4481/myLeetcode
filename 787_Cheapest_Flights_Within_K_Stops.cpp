#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> cost(n, INT_MAX);

        for(auto& flight: flights){
            if(flight[0] == src){
                cost[flight[1]] = flight[2];
            }
        }
        cost[src] = 0;
        for(int i = 1; i <= k; ++i){
            std::vector<int> cost_prev = cost;
            for(auto& flight: flights){
                if((cost_prev[flight[0]]) != INT_MAX){
                    cost[flight[1]] = std::min(cost[flight[1]], cost_prev[flight[0]]+flight[2]);
                }
            }
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};



class Solution1 
{
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) 
    {
        const int ceiling = 200000;
        std::vector<std::vector<int>> info(n, std::vector<int>(n, ceiling));        

        for(auto& srcDstPrice: flights)
        {
            info[srcDstPrice[0]][srcDstPrice[1]] = srcDstPrice[2];
        }

        std::vector<int> ans(n, ceiling);
        std::vector<int> ansCopy;
        ans[src] = 0;
        std::unordered_set<int> Q1;
        std::unordered_set<int> Q2;
        
        //city, key
        Q1.insert(src);
        int stop = 0;

        while(stop <= k)
        {
            ansCopy = ans;
            for(auto& city: Q1)
            {
                const auto& transport = info[city];
                for(int i = 0; i < n; ++i)
                {
                    if(transport[i] != ceiling && ans[i] > ansCopy[city] + transport[i])
                    {
                        ans[i] = ansCopy[city] + transport[i];
                        Q2.insert(i);
                    }    
                }
            }        
            Q1.swap(Q2);    
            Q2.clear();
            ++stop;
        }

        return ans[dst] == ceiling ? -1 : ans[dst];
    }
};