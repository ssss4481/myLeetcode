#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> costs(s.size(), 0);
        for(int i = 0; i < s.size(); ++i){
            costs[i] = abs(s[i]-t[i]);
        }
        int result = 0;

        int lo = 0;
        int hi = 0;
        int current_cost = 0;
        while(hi < s.size()){
            current_cost += costs[hi];
            ++hi;
            if(current_cost > maxCost){
                result = max(result, hi-lo-1);
                while(current_cost > maxCost){
                    current_cost -= costs[lo];
                    ++lo;
                }
            }else if(hi == s.size()){
                result = max(result, hi-lo);
            }
        }
        return result;
    }
};