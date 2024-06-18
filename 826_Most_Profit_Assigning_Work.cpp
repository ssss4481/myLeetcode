#include <vector>
#include <algorithm>
#include <map>
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> diff_to_max_profit;
        const int n = difficulty.size();

        for(int i = 0; i < n; ++i){
            int& diff = difficulty[i];
            int& p = profit[i];

            if(diff_to_max_profit.empty()){
                diff_to_max_profit[diff] = p;
            }else{
                auto it = diff_to_max_profit.lower_bound(diff);
                if(it == diff_to_max_profit.end()){
                    it = prev(it);//diff less than current
                    if(it->second < p){
                        diff_to_max_profit[diff] = p;
                    }
                }else{
                    //(6, ), (8, ) -> 7
                    if(it->first != diff && (it == diff_to_max_profit.begin() || prev(it)->second < p)){//lower_bound > diff
                        diff_to_max_profit[diff] = p;
                    }
                    while(it != diff_to_max_profit.end() && p > it->second){
                        it->second = p;
                        it = next(it);
                    }
                }
            }
        }

        int result = 0;
        for(auto& w: worker){
            auto it = diff_to_max_profit.upper_bound(w);
            if(it != diff_to_max_profit.begin()){
                it = prev(it);
                result += it->second;
            }
        }
        return result;
    }
};