#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> res = {1};
        res.reserve(n);
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while(res.size() < n){
            int r2 = res[i2]*2;
            int r3 = res[i3]*3;
            int r5 = res[i5]*5;

            int next_ugly_number = std::min({r2, r3, r5});
            if(r2 == next_ugly_number){
                ++i2;
            }
            if(r3 == next_ugly_number){
                ++i3;
            }
            if(r5 == next_ugly_number){
                ++i5;
            }
            res.push_back(next_ugly_number);
        }
        return res.back();
    }
};