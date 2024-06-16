#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int result = 0;
        for(int i = 0; i < nums.size() && miss <= n;){
            if(nums[i] <= miss){
                miss += nums[i];
                ++i;
            }else{
                miss += miss;
                ++result;
            }
        }

        while(miss <= n){
            miss += miss;
            ++result;
        }

        return result;
        
    }
};


class Solution1 {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int result = 0;
        int i = 0;
        while(miss <= n){
            if(i < nums.size() && miss >= nums[i]){
                miss += nums[i];
                ++i;
            }else{
                miss += miss;
                ++result;
            }
        }
        return result;
        
    }
};