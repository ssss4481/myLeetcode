#include <vector>
#include <queue>
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
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) 
    {
        std::sort(deck.begin(), deck.end());

        std::queue<int> Q;
        for(int i = 0; i < deck.size(); ++i)
        {
            Q.push(i);
        }

        std::vector<int> ret(deck.size());
        bool reveal = true;
        for(int i = 0; !Q.empty();)
        {
            if(reveal)
            {
                ret[Q.front()] = deck[i++];
                Q.pop();
            }
            else
            {
                Q.push(Q.front());
                Q.pop();
            }
            reveal = !reveal;
        }
        return ret;
    }
};