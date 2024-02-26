#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
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

int main(int argc, char const *argv[])
{
    return 0;
}
