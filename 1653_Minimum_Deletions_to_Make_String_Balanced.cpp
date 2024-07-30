#include <iostream>
#include <string>
#include <vector>
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
    int minimumDeletions(string s) {
        const int n = s.size();
        vector<int> dp(n, 0);

        int b_count = s.front() == 'b' ? 1 : 0;
    
        for(int i = 1; i < n; ++i){
            if(s[i] == 'a'){
                dp[i] = min(dp[i-1]+1, b_count);
            }else{
                ++b_count;
                dp[i] = dp[i-1];
            }
        }
        return dp.back();
    }
};
