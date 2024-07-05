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
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }

        vector<int> small(4);
        vector<int> large(4);

        make_heap(nums.begin(), nums.end());
        for(int i = 0; i <= 3; ++i){
            pop_heap(nums.begin(), nums.end()-i);
            large[i] = *(nums.end()-1-i);
        }

        make_heap(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i <= 3; ++i){
            pop_heap(nums.begin(), nums.end()-i, greater<int>());
            small[i] = *(nums.end()-1-i);
        }

        int result = INT_MAX;

        for(int d = 0; d <= 3; ++d){
            result = min(result, large[d]-small[3-d]);
        }
        
        return result;
    }
};

class Solution1 {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }
        sort(nums.begin(), nums.end());

        int result = INT_MAX;
        for(int i = 0; i <= 3; ++i){
            result = min(result, nums[nums.size()-4+i] - nums[i]);
        }
        return result;
    }
};
