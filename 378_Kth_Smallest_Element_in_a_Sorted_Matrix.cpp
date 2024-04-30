#include <vector>
#include <algorithm>
class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int lo = matrix.front().front();
        int hi = matrix.back().back();

        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            int count = 0;
            for(auto& row: matrix){
                count += (std::upper_bound(row.begin(), row.end(), mid) - row.begin());
            }
            if(count < k){
                lo = mid+1;
            }else{
                hi = mid;
            }
        }
        return lo;
    }
};