#include <string>
using namespace std;


class Solution {
public:
    int countKeyChanges(string s) {
        char prev = tolower(s[0]);
        int change = 0;
        for(int i = 1; i < s.size(); ++i){
            char current = tolower(s[i]);
            if(current != prev){
                prev = current;
                ++change;
            }
        }
        return change;        
    }
};