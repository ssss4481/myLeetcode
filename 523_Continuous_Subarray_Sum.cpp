#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        if(n < 2){
            return false;
        }

        vector<int> prefix_sum(n+1, 0);
        
        for(int i = 0; i < n; ++i){
            prefix_sum[i+1] = (prefix_sum[i]+nums[i])%k;
        }
        
        unordered_map<int, int> hashtable;
        hashtable[0] = 0;
        for(int i = 1; i < n+1; ++i){
            int r = prefix_sum[i];
            if(hashtable.count(r) == 1){
                if(hashtable[r] < i-1){
                    return true;
                }
            }else{
                hashtable[r] = i;
            }
        }
        return false;        
    }
};