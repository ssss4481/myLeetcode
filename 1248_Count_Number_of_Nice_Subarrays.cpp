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
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> oddPos;        
        oddPos.emplace_back(-1);
        for(int i = 0; i < nums.size(); ++i){
            if((nums[i] & 1) != 0){
                oddPos.emplace_back(i);
            }
        }
        oddPos.emplace_back(static_cast<int>(nums.size()));
        int lo = 1;
        int hi = lo+k-1;
        int result = 0;
        const int boundary = static_cast<int>(oddPos.size())-1;
        while(hi < boundary){
            result += ((oddPos[lo]-oddPos[lo-1]) * (oddPos[hi+1]-oddPos[hi]));
            ++lo;
            ++hi;
        }
        return result;
    }
};