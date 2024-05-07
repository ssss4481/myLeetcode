#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <iostream>
static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

struct pair_hash{
    size_t operator()(const pair<int, int>& p)const {
        return p.first ^ p.second;
    }
};

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        const int m = nums1.size();
        const int n = nums2.size();

        
        auto getSum = [&](const pair<int, int>& p){
            return nums1[p.first]+nums2[p.second];
        };
        auto cmp = [&](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2){
            return p1.first > p2.first;
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> PQ(cmp);
        unordered_set<pair<int, int>, pair_hash> visited;
        vector<vector<int>> res;
        PQ.push(make_pair<int, pair<int, int>>(getSum({0, 0}), {0, 0}));
        visited.insert({0, 0});

        while(k-- > 0){
            auto top = PQ.top();
            PQ.pop();
            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            if(i + 1 < m && visited.count({i+1, j}) == 0){
                PQ.push(make_pair<int, pair<int, int>>(getSum({i+1, j}), {i+1, j}));
                visited.insert({i+1, j});
            }

            if(j + 1 < n && visited.count({i, j+1}) == 0){
                PQ.push(make_pair<int, pair<int, int>>(getSum({i, j+1}), {i, j+1}));
                visited.insert({i, j+1});
            }            
        }
        
        return res;
    }
};

class Solution1 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        const int m = nums1.size();
        const int n = nums2.size();

        
        auto getSum = [&](const pair<int, int>& p){
            return nums1[p.first]+nums2[p.second];
        };
        auto cmp = [&](const pair<int, pair<int, int>>& p1, const pair<int, pair<int, int>>& p2){
            return p1.first > p2.first;
        };

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> PQ(cmp);
        set<pair<int, int>> visited;
        vector<vector<int>> res;
        PQ.push(make_pair<int, pair<int, int>>(getSum({0, 0}), {0, 0}));
        visited.insert({0, 0});

        while(k-- > 0){
            auto top = PQ.top();
            PQ.pop();
            int i = top.second.first;
            int j = top.second.second;

            res.push_back({nums1[i], nums2[j]});

            if(i + 1 < m && visited.count({i+1, j}) == 0){
                PQ.push(make_pair<int, pair<int, int>>(getSum({i+1, j}), {i+1, j}));
                visited.insert({i+1, j});
            }

            if(j + 1 < n && visited.count({i, j+1}) == 0){
                PQ.push(make_pair<int, pair<int, int>>(getSum({i, j+1}), {i, j+1}));
                visited.insert({i, j+1});
            }            
        }
        
        return res;
    }
};