#include <vector>
#include <iostream>
#include <algorithm>

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
    vector<int> sortArray(vector<int>& nums) {
        const int n = nums.size()-1;
        make_heap(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            pop_heap(nums.begin(), nums.end()-i);
        }
        return nums;
    }
};