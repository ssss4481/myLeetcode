#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <limits>
#include <iostream>
static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size();

        auto sort_cmp = [&](int i, int j){
            return static_cast<double>(wage[i])/quality[i] < static_cast<double>(wage[j])/quality[j];
        };

        auto PQ_cmp = [&](int i, int j){
            return quality[i] < quality[j];
        };

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), sort_cmp);

        priority_queue<int, vector<int>, decltype(PQ_cmp)> PQ(PQ_cmp);

        int Q_sum = 0;
        double res = numeric_limits<double>::max();

        for(int i = 0; i < n; ++i){
            Q_sum += quality[idx[i]];
            PQ.push(idx[i]);
            if(PQ.size() == k){
                double current = static_cast<double>(Q_sum)*wage[idx[i]]/quality[idx[i]];
                res = min(res, current);
                Q_sum -= quality[PQ.top()];
                PQ.pop();
            }
        }

        return res;
    }
};