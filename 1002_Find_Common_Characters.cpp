#include <vector>
#include <string>
#include <numeric>
using namespace std;


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        const int n = words.size();
        vector<vector<int>> count(26, vector<int>(n, 0));
        
        for(int i = 0; i < n; ++i){
            for(auto& c : words[i]){
                ++count[c-'a'][i];
            }
        }

        vector<string> res;

        for(int i = 0; i < 26; ++i){
            int amount = *min_element(count[i].begin(), count[i].end());
            string c = " ";
            c[0] = 'a'+i;
            for(int j = 0; j < amount; ++j){
                res.emplace_back(c);
            }
        }
        return res;
    }
};