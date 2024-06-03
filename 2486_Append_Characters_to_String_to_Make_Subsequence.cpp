#include <string>
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