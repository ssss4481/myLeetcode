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
    bool canAliceWin(vector<int>& nums) {
        int singled = 0;
        int doubled = 0;
        for(auto& n : nums){
            if(n >= 10){
                doubled += n;
            }else{
                singled += n;
            }
        }
        return singled != doubled;
        
    }
};