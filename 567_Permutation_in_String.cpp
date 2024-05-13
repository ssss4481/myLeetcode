#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }

        int count[128] = {0};
        for(int i = 0; i < s1.size(); ++i){
            ++count[s1[i]];
        }

        int match = s1.size();
        for(int i = 0; i < s1.size(); ++i){
            if(count[s2[i]] > 0){
                --match;
            }
            --count[s2[i]];
        }

        if(match == 0){
            return true;
        }            
        
        int lo = 0;
        for(int i = s1.size(); i < s2.size(); ++i){
            if(count[s2[i]] > 0){
                --match;
            }
            --count[s2[i]];
            if(count[s2[lo]] >= 0){
                ++match;
            }
            ++count[s2[lo]];
            ++lo;
            if(match == 0){
                return true;
            }
        }

        return false;
    }
};