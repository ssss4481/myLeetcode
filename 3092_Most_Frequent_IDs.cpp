#include <bits/stdc++.h>


class Solution {
public:
    
    std::vector<long long> mostFrequentIDs(std::vector<int>& nums, std::vector<int>& freq) {
        auto cmp = [](const std::pair<long long, int>& a, const std::pair<long long, int>& b){
            const long long& a_freq = a.first;
            const long long& b_freq = b.first;
            return a_freq < b_freq;
        };
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, decltype(cmp)> PQ(cmp);
        std::unordered_map<int, long long> map;//ID to freq
        std::vector<long long> ans;
        for(int i = 0; i < nums.size(); ++i){
            map[nums[i]] += freq[i];
            PQ.push({map[nums[i]], nums[i]});
            while(PQ.top().first != map[PQ.top().second]){
                PQ.pop();
            }
            ans.push_back(PQ.top().first);
        }

        return ans;
    }
};