#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        const int n = energy.size();
        for(int i = 0; i < k; ++i){
            res = max(res, maxSubarray(energy, k, n-1-i));
        }
        return res;
    }

    int maxSubarray(vector<int>& energy, const int k, int start){
        int cur = energy[start];
        int res = cur;
        for(int i = start-k; i >= 0; i-=k){
            cur += energy[i];
            res = max(res, cur);
        }

        return res;

    }

};