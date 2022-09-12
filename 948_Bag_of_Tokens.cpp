#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        int lo = 0;
        int hi = tokens.size()-1;

        sort(tokens.begin(), tokens.end());

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


int main()
{
    return 0;
}