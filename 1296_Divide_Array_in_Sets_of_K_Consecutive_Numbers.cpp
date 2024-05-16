#include <map>
#include <vector>
using namespace std;


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> occurences;
        for(auto& n : nums){
            ++occurences[n];
        }

        while(!occurences.empty()){
            vector<int> should_be_removed;
            auto it = occurences.begin();
            int prev = (*it).first;
            --occurences[prev];
            if(occurences[prev] == 0){
                should_be_removed.push_back(prev);
            }
            for(int i = 1; i <= k-1; ++i){
                ++it;
                if(it == occurences.end() || prev + 1 != (*it).first){
                    return false;
                }
                prev = (*it).first;
                --occurences[prev];
                if(occurences[prev] == 0){
                    should_be_removed.push_back(prev);
                }                
            }
            for(auto& n: should_be_removed){
                occurences.erase(n);
            }
        }
        return true;
    }
};