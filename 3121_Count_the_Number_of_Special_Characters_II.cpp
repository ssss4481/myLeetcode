#include <string>
class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        int state[26] = {0};
        
        for(auto& c : word){
            if(c >= 'A' && c <= 'Z'){
                if(state[c-'A'] == 0){
                    state[c-'A'] = -1;
                }else if(state[c-'A'] == 1){
                    state[c-'A'] = 2;
                }
            }else{
                if(state[c-'a'] == 0){
                    state[c-'a'] = 1;
                }else if(state[c-'a'] == 2){
                    state[c-'a'] = -1;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < 26; ++i){
            if(state[i] == 2){
                ++ret;
            }
        }

        return ret;
    }
};