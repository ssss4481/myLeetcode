#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution 
{
public:
    int tallestBillboard(vector<int>& rods) 
    {        
        const int arrSize = 1 + std::accumulate(rods.begin(), rods.end(), 0);
        vector<int> DP(arrSize, -1);
        DP[0] = 0;

        for(const int& rod:rods)
        {
            vector<int> copyDP(DP);//do nothing    
            for(int diff = 0; diff < arrSize - rod; ++diff)
            {    
                if(copyDP[diff] < 0)
                {
                    continue;
                }

                const int& originTaller = copyDP.at(diff);
                DP.at(diff+rod) = max(DP.at(diff+rod), originTaller+rod);

                const int newDiff = abs(rod-diff);
                DP.at(newDiff) = max({DP.at(newDiff), originTaller-diff+rod, originTaller});
            }
        }
        
        return DP.at(0);        
    }
};

