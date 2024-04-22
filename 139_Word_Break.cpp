#include <unordered_set>
#include <vector>
#include <string>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
        std::unordered_set<int> lens;
        for(auto& word: wordDict){
            lens.insert(word.length());
        }
        const int n = s.length();
        bool valid[n+1];
        memset(valid, 0, (n+1)*sizeof(bool));
        valid[0] = true;
        for(int i = 0; i <= n; ++i){
            if(!valid[i]){
                continue;
            }
            for(auto& len: lens){
                if(i+len > n || valid[i+len]){
                    continue;
                }
                if(word_set.count(s.substr(i, len)) == 1){
                    valid[i+len] = true;
                }
            }
        }
        return valid[n];
    }
};