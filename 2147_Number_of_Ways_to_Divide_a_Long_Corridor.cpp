#include <string>
#include <vector>
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
    int numberOfWays(std::string corridor) 
    {
        std::vector<int> choices;
        int seatCount = 0;
        int loRight = -1;
        int hiLeft;
        for(int i = 0; i < corridor.length(); ++i)
        {
            if(corridor[i] == 'S')
            {
                if(seatCount == 0)
                {
                    ++seatCount;
                    hiLeft = i;
                }
                else
                {               
                    if(loRight != -1)
                    {
                        choices.push_back(hiLeft-loRight);
                    }
                    seatCount = 0;
                    loRight = i;                    
                }
            }
        }

        if(seatCount != 0 || loRight == -1)
        {
            return 0;
        }

        long long int ret = 1;
        for(auto& n: choices)
        {
            ret *= n;
            ret %= 1000000007;
        }
        return ret;     
    }
};