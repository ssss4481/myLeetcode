#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        int count[26] = {0};
        for(auto& c : s){
            ++count[c-'a'];
        }
        int res = count[0];
        for(int i = 1; i < 26; ++i){
            res = __gcd(res, count[i]);
        }
        return s.length()/res;
    }
};