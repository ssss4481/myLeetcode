#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<string> dict;

        for(int i = 0; i+9 < s.size(); ++i){
            string subString = s.substr(i, 10);
            if(dict.count(subString) == 1){
                res.insert(subString);
            }else{
                dict.insert(subString);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};