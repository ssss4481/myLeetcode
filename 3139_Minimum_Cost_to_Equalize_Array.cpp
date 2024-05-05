#include <vector>
#include <algorithm>
#include <numeric>
#include <deque>
using namespace std;
#define MOD 1000000007

class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        int max_num = *std::max_element(nums.begin(), nums.end());

        if(2*cost1 <= cost2){
            long long op = 0;
            for(auto& n : nums){
                op += (max_num-n);
            }
            return static_cast<int>( (op*cost1) % MOD);
        }

        deque<int> delta;
        for(auto& n : nums){
            if(max_num-n > 0){
                delta.push_back(max_num-n);
            }
        }
        long long op2 = 0;        
        while(delta.size() > 1){
            int f = delta.front();
            int b = delta.back();
            delta.pop_front();
            delta.pop_front();

            int m = min(f, b);
            f -= m;
            b -= m;
            op2 += m;
            if(f > 0){
                delta.push_front(f);
            }else if(b > 0){
                delta.push_back(b);
            }
        }
        long long op1 = 0;
        if(delta.size() == 1){
            op1 = delta.back();
        }

        long long res = ((op1*cost1%MOD) + (op2*cost2%MOD))%MOD;
        return static_cast<int>(res);
    }
};