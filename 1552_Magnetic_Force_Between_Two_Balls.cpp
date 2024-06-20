#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = 1000000000;
        int result = 1;
        --m;//always put 1 ball on position[0]

        auto valid = [&position](int distance, int m)->bool {
            int next = position[0] + distance;
            for(int i = 1; i < position.size() && m > 0; ++i){
                if(position[i] >= next){
                    --m;
                    next = position[i]+distance;
                }
            }
            return (m == 0);
        };

        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(valid(mid, m)){
                result = max(mid, result);
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return result;
    }
};