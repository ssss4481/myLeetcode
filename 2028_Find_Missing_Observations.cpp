#include <iostream>
#include <vector>

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
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean * (rolls.size() + n);
        for(auto& val: rolls){
            sum -= val;
        }

        if(sum < n || sum > 6*n){
            return {};
        }

        sum -= n;
        vector<int> result(n, 1);

        for(auto& val: result){
            if(sum >= 5){
                val += 5;
                sum -= 5;
            }else{
                val += sum;
                sum = 0;
            }

            if(sum == 0){
                break;
            }
        }

        return result;
    }
};