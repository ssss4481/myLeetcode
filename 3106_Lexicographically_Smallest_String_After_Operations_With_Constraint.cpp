#include <string>


class Solution {
public:
    std::string getSmallestString(std::string s, int k) {
        if(k == 0){
            return s;
        }
        int i = 0;
        while(k > 0 && i < s.length()){

            int d = distance(int('a'), int(s[i]));
            if(k >= 26){
                k -= d;
                s[i] = 'a';
            }else{
                if(k < d){
                    s[i] -= char(k);
                    k = 0;
                }else if(k == d){
                    s[i] = 'a';
                    k = 0;
                }else{
                    s[i] = 'a';
                    k -= d;
                }
            }
            ++i;
        }
        return s;
    }
    
    
    int distance(int a, int b){
        if(a > b){
            std::swap(a, b);
        }
        return static_cast<int>(std::min(b - a, a + 26 - b));
    }

};