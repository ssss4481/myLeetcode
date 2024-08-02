#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    int minSwaps(vector<int>& nums) {
        const int n = nums.size();
        int result = n+1;
        int totalOneCount = accumulate(nums.begin(), nums.end(), 0);

        int oneCount = nums.front();
        int end = 0;

        for(int start = 0; start < n; ++start){

            if(start != 0){
                oneCount -= nums[start-1];
            }

            while(end - start + 1 < totalOneCount){
                ++end;
                oneCount += nums[end%n];
            }

            result = min(result, totalOneCount - oneCount);
        }

        return result;
    }
};