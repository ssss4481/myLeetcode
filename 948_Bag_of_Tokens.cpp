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
class Solution
{
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power)
    {
        int lo = 0;
        int hi = tokens.size()-1;

        std::sort(tokens.begin(), tokens.end());

        int score = 0;

        if(tokens.size() > 0 && power >= tokens[0])
        {
            while(lo <= hi)
            {
                if(power >= tokens[lo])
                {
                    ++score;
                    power -= tokens[lo];
                    ++lo;
                }
                else if(score > 0 && hi != lo)
                {
                    --score;
                    power += tokens[hi];
                    --hi;
                }
                else
                {
                    break;
                }
            }
        }
        return score;
    }
};


