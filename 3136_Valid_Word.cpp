#include <string>

using namespace std;


class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3){
            return false;
        }        
        
        bool hasVowel = false;
        bool hasConsonant = false;

        for(auto& c: word){
            if(isalpha(c)){
                if(isVowel(c)){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(!isdigit(c)){
                return false;
            }
        }
        return hasVowel && hasConsonant;
        
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};