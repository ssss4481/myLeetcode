#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        for(int i = 1; i <= s.length()/2; ++i){
            if(s.length()%i == 0 && isValid(s, i)){
                return i;
            }
        }
        return s.length();
    }
    bool isValid(string& s, int len){
        int count1[26] = {0};
        for(int i = 0; i < len; ++i){
            ++count1[s[i]-'a'];
        }
        for(int start = len; start < s.length(); start += len){
            int count2[26] = {0};
            for(int i = 0; i < len; ++i){
                ++count2[s[start+i]-'a'];
            }            
            if(!same(count1, count2)){
                return false;
            }
        }
        return true;
    }

    bool same(int count1[], int count2[]){
        for(int i = 0; i < 26; ++i){
            if(count1[i] != count2[i]){
                return false;
            }
        }
        return true;
    }
};