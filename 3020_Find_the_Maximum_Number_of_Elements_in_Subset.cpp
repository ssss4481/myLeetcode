#include <queue>
#include <unordered_map>
#include <algorithm>
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
    int maximumLength(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        unordered_map<int, int> counts;

        int best = 1;
        
        for(auto& num:nums){
            if(counts.count(num) == 0){
                PQ.push(num);
            }
            ++counts[num];
        }

        if(counts.count(1)){
            PQ.pop();
            if(counts[1] % 2 == 1){
                best = max(best, counts[1]);
            }else{
                best = max(best, counts[1]-1);
            }
        }
        
        while(!PQ.empty()){
            int base = PQ.top();
            PQ.pop();
            long long cur = base;
            int size = 1;
            while(true){
                if(cur*cur > INT_MAX){
                    break;
                }                
                if(counts[cur] >= 2 && counts[cur*cur] >= 1){
                    size += 2;
                }else{
                    break;
                }
                cur *= cur;
            }
            best = max(size, best);
        }

        return best;
    }
};