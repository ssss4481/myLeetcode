#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes) {
        long long res[n];
        res[0] = 1;
        int idx[primes.size()];
        memset(idx, 0, sizeof(idx));
        int i = 1;
        while(i < n){
            long long min_val = INT_MAX;
            for(int j = 0; j < primes.size(); ++j){
                min_val = std::min(min_val, primes[j] * res[idx[j]]);
            }
            for(int j = 0; j < primes.size(); ++j){
                if(min_val == primes[j] * res[idx[j]]){
                    ++idx[j];
                }
            }
            res[i++] = static_cast<int>(min_val);
        }
        return res[n-1];
    }
};