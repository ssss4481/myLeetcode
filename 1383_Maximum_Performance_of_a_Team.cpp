#include <vector>
#include <queue>
#include <algorithm>

//typedef long long int LL;

using namespace std;


class Solution{
public:
    typedef long long int LL;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        const int mod = (int)1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> combine;

        for(int i = 0; i < n; ++i)
        {
            combine.push_back({efficiency[i], speed[i]});
        }

        sort(combine.rbegin(), combine.rend());

        // Sort the "combine" array such that the larger the efficiency is, the smaller the index.
        // When we iterate the array, the new item's efficiency will be the min value.

        LL totalSpeed = 0;
        LL ans = 0;

        for(int i = 0; i < n; ++i)
        {
            int curEff = combine[i].first;
            int currSpeed = combine[i].second;
            if(pq.size() == k)
            {
                totalSpeed -= pq.top();
                pq.pop();
            }
            pq.push(currSpeed);
            totalSpeed += currSpeed;
            ans = max(ans, totalSpeed * curEff);
        }
        return ans % mod;
    }
};

int main()
{

    return 0;
}