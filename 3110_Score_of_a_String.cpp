#include <string>
#include <cmath>

class Solution {
public:
    int scoreOfString(std::string s) {
        int score = 0;
        for(int i = 1; i < s.length(); ++i){
            score += abs(int(s[i])-int(s[i-1]));
        }
        return score;
    }
};