#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 1e9;

        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            long long time = 0;
            for(auto& p: piles){
                time += (p/mid);
                if(p % mid != 0){
                    ++time;
                }
            }
            if(time <= h){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return lo;
    }
};