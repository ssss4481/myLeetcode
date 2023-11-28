#include <vector>
#include <algorithm>
#include <iostream>


class Solution 
{
public:
    int maxCoins(std::vector<int>& piles) 
    {
        const int split = piles.size()/3;
        std::sort(piles.begin(), piles.end());
        int ret = 0;
        int greedyIdx = piles.size()-2;

        while (greedyIdx >= split)
        {
            ret += piles[greedyIdx];
            greedyIdx -= 2;
        }
        
        return ret;        
    }
};