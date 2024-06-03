#include <string>
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
    int appendCharacters(string s, string t) {
        int ti = 0;
        for(auto& c: s){
            if(c == t[ti]){
                ++ti;
            }
            if(ti == t.size()){
                return 0;
            }
        }
        return static_cast<int>(t.size())-ti;
    }
};