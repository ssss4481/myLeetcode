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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long res = 0;
        for(int i = 0; i < k; ++i){
            if(happiness[i] <= i){
                break;
            }
            res += happiness[i]-i;
        }

        return res;
    }
};