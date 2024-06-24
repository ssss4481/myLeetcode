#include <vector>
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
    int minKBitFlips(vector<int>& nums, int k) {
        const int n = nums.size();
        int acc_filped_by_window = 0;
        int result = 0;

        for(int i = 0; i < n; ++i){
            if(i >= k && nums[i-k] == -1){
                --acc_filped_by_window;
            }

            if((acc_filped_by_window & 1) == nums[i]){
                if(i+k > n){
                    return -1;
                }
                ++acc_filped_by_window;
                nums[i] = -1;
                ++result;
            }
        }
        return result;
    }
};