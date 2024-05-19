#include <string>
using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        if(s1[0] != s2[0] || s1[0] != s3[0]){
            return -1;
        }
        
        int i = 0;
        /*
              i
            abc
            abb
            ab
        
        */
        
        while(i < s1.size() && i < s2.size() && i < s3.size()){
            if(s1[i] == s2[i] && s1[i] == s3[i]){
                ++i;
            }else{
                break;
            }
        }
        
        return s1.size()-i + s2.size()-i + s3.size()-i;
        
    }
};