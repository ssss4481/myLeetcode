#include <string>
#include <stack>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stack<std::string> words;
        
        bool word_detected = false;
        int lo = -1;
        for(int i = 0; i < s.length(); ++i){
            if(!word_detected){
                if(s[i] != ' '){
                    word_detected = true;
                    lo = i;
                }
            }else{
                if(s[i] == ' '){
                    words.push(s.substr(lo, i-lo));
                    word_detected = false;
                    lo = -1;
                }
            }
        }

        if(lo != -1){
            words.push(s.substr(lo));
        }

        std::string ret = "";
        while(!words.empty()){
            ret += words.top();
            ret.push_back(' ');
            words.pop();
        }
        ret.pop_back();

        return ret;
    }
};