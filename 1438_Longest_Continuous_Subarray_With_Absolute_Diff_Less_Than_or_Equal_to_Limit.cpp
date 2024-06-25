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

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        using value_index = pair<int, int>;

        auto min_cmp = [](const value_index& lhs, const value_index& rhs){
            if(lhs.first == rhs.first){
                return lhs.second > rhs.second;
            }
            return lhs.first > rhs.first;
        };
        auto max_cmp = [](const value_index& lhs, const value_index& rhs){
            if(lhs.first == rhs.first){
                return lhs.second > rhs.second;
            }
            return lhs.first < rhs.first;
        };

        priority_queue<value_index, vector<value_index>, decltype(min_cmp)> min_heap(min_cmp);
        priority_queue<value_index, vector<value_index>, decltype(max_cmp)> max_heap(max_cmp);

        int lo = 0;
        int result = 1;

        auto clear_index_not_in_range = [&](){
            while(!min_heap.empty() && min_heap.top().second < lo){
                min_heap.pop();
            }
            while(!max_heap.empty() && max_heap.top().second < lo){
                max_heap.pop();
            }            
        };

        for(int hi = 0; hi < nums.size(); ++hi){
            min_heap.push({nums[hi], hi});
            max_heap.push({nums[hi], hi});

            while(max_heap.top().first - min_heap.top().first > limit){
                lo = min(max_heap.top().second, min_heap.top().second)+1;
                clear_index_not_in_range();
            }
            result = max(result, hi - lo + 1);
        }

        return result;
    }
};