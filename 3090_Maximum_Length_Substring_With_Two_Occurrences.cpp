#include <bits/stdc++.h>

class Solution {
public:
    int maximumLengthSubstring(std::string s) {
        int count[26] = {0};
        int lo = 0;
        int len = 2;

        for(int i = 0; i < s.length(); ++i){
            if(++count[s[i]-'a'] > 2){  
                len = std::max(len, i-lo);
                while (count[s[i]-'a'] > 2){
                    --count[s[lo]-'a'];
                    ++lo;
                }
            }
        }

        len = std::max(len, int(s.length())-lo);

        return len;
        
    }
};