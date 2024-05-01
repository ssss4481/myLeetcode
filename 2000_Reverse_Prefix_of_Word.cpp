#include <string>

class Solution {
public:
    std::string reversePrefix(std::string word, char ch) {
        for(int i = 0; i < word.size(); ++i){
            if(word[i] == ch){
                for(int j = 0; j < i; ++j){
                    std::swap(word[i], word[j]);
                    --i;
                }
                break;
            }
        }
        return word;
    }
};