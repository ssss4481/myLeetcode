#include <map>
#include <vector>
using namespace std;


#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }

        map<int, int> counts;
        for(auto& n : hand){
            ++counts[n];
        }

        while(!counts.empty()){
            vector<int> need_erase;
            auto it = counts.begin();
            int cur = (*it).first;
            --((*it).second);
            if((*it).second == 0){
                need_erase.push_back((*it).first);
            }            

            for(int i = 1; i < groupSize; ++i){
                ++it;
                if(it == counts.end() || (*it).first != cur+1){
                    return false;
                }
                --((*it).second);
                if((*it).second == 0){
                    need_erase.push_back((*it).first);
                }
                cur = (*it).first;
            }

            for(auto& n : need_erase){
                counts.erase(n);
            }

        }
        return true;
    }
};
