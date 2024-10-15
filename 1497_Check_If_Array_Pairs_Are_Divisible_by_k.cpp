#include <iostream>
#include <vector>
#include <unordered_map>

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
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int, int> mods;

        for(auto& n: arr){
            int mod = (n%k+k)%k;
            mods[mod]++;
        }

        for(auto& p: mods){
            if(p.first == 0 ){
                if((p.second & 1) != 0){
                    return false;
                }
            }else if(mods[k - p.first] != p.second){
                return false;
            }
        }
   
        return true;        
    }
};