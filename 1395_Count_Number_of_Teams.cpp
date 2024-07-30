#include <iostream>
#include <vector>
#include <set>

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
    int numTeams(vector<int>& rating) {
        const int n = rating.size();

        vector<int> rightLargerCount(n, 0);
        vector<int> rightSmallerCount(n, 0);

        set<int> nums;

        for(int i = n-1; i >= 0; i--){
            auto it = nums.insert(rating[i]).first;
            rightLargerCount[i] = distance(it, prev(nums.end()));
            rightSmallerCount[i] = distance(nums.begin(), it);
        }

        int result = 0;
        nums.clear();
        for(int i = 0; i < n; ++i){
            auto it = nums.insert(rating[i]).first;
            result += distance(it, prev(nums.end())) * rightSmallerCount[i];
            result += distance(nums.begin(), it) * rightLargerCount[i];
        }

        return result;
    }
};