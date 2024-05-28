#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count[1001] = {0};

        for(auto& n : nums){
            ++count[n];
        }

        int acc = 0;

        for(int i = 1000; i >= 0; --i){
            acc += count[i];
            if(acc == i){
                return acc;
            }
        }
        return -1;
    }
};