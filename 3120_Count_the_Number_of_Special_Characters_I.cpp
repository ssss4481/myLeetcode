#include <string>
class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        bool found[256] = {false};
        
        for(auto& c :word){
            found[c] = true;
        }
        
        int ret = 0;
        for(int c = 'A'; c <= 'Z'; ++c){
            if(found[c] && found[c+'a'-'A']){+
                ++ret;
            }
        }
        
        return ret;
        
    }
};