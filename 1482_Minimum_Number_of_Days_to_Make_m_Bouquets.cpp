#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int total = m*k;
        
        if(total > bloomDay.size()){
            return -1;
        }
        int lo = 0;
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        
        if(total == bloomDay.size()){
            return hi;
        }

        int bestAns = INT_MAX;

        while(lo < hi){
            int mid = (lo+hi)/2;
            int start = -1;
            int b = 0;
            for(int i = 0; i < bloomDay.size(); ++i){
                if(bloomDay[i] <= mid){
                    if(start == -1){
                        start = i;
                    }
                }else{
                    if(start != -1){
                        b += (i-start)/k;
                        start = -1;
                    }
                }
            }
            if(b >= m){
                bestAns = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return bestAns;
    }
};