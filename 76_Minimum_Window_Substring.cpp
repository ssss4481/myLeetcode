#include <string>
#include <vector>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) 
    {
        if(s.length() < t.length()){
            return "";
        }
        int map[128] = {0};
        int count = t.length();
        int minLen = INT_MAX;
        int startIndex;

        for(auto& c : t){
            ++map[c];
        }

        int lo = 0;
        int hi = 0;
        
        while(hi < s.length()){
            if(map[s[hi]] > 0){
                --count;
            }
            --map[s[hi]];
            ++hi;

            while (count == 0){
                if(hi-lo < minLen){
                    startIndex = lo;
                    minLen = hi-lo;
                }
                ++map[s[lo]];
                if(map[s[lo]] > 0){
                    ++count;
                }
                ++lo;
            }
        }
        
        return minLen != INT_MAX ? s.substr(startIndex, minLen) : "";
    }
};