#include <vector>
#include <numeric>
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
    int leastInterval(std::vector<char>& tasks, int n) 
    {
        std::vector<int> counts(26);
        for(auto& c : tasks)
        {
            ++counts[int(c-'A')];
        }

        std::sort(counts.rbegin(), counts.rend());

        int round = counts[0]-1;
        int capacity = round * n;

        for(int i = 1; i < 26; ++i)
        {
            capacity -= std::min(round, counts[i]);
        }

        if(capacity <= 0)
        {
            return int(tasks.size());
        }
        else
        {
            return int(tasks.size()) + capacity;
        }
    }
};