#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

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
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
    {
        std::deque<int> dq;
        dq.push_back(0);
        for(int i = 1; i < k; ++i)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[k])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }



    }
};


class Solution1 
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
    {
        typedef std::pair<int, int> pi;
        const int n = nums.size();

        auto cmp = [] (pi& a, pi& b)
        {
            return a.first < b.first;
        };

        std::priority_queue<pi, std::vector<pi>, decltype(cmp)> PQ(cmp);

        for(int i = 0; i < k-1; ++i)
        {
            PQ.push({nums[i], i});
        }

        std::vector<int> ret;
        int lowerBound = 0;
        for(int i = k-1; i < n; ++i)
        {
            PQ.push({nums[i], i});
            while(PQ.top().second < lowerBound)
            {
                PQ.pop();
            }
            ret.push_back(PQ.top().first);
            ++lowerBound;
        }
        return ret;
    }
};





