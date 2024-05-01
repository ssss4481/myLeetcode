#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
        std::unordered_map<std::string, int> word_to_index_map;
        std::set<int> len_set;

        for(int i = 0; i < words.size(); ++i){
            word_to_index_map[words[i]] = i;
            len_set.insert(words[i].size());
        }

        std::vector<std::vector<int>> result;

        for(int i = 0; i < words.size(); ++i){
            std::string s = words[i];
            std::reverse(s.begin(), s.end());
            if(word_to_index_map.count(s) != 0 && i != word_to_index_map[s]){
                result.push_back({i, word_to_index_map[s]});
            }
            int len = s.size();
            for(auto it = len_set.begin(); *it < len; ++it){
                int c_len = *it;
                if(isPalindrome(s, c_len, len-1)){
                    std::string candidate = s.substr(0, c_len);
                    if(word_to_index_map.count(candidate) == 1){
                        result.push_back({word_to_index_map[candidate], i});
                    }
                }
                if(isPalindrome(s, 0, len-c_len-1)){
                    std::string candidate = s.substr(len-c_len);
                    if(word_to_index_map.count(candidate) == 1){
                        result.push_back({i, word_to_index_map[candidate]});
                    }                    
                }
            }
        }
        return result;
    }

    bool isPalindrome(std::string& s, int lo, int hi){
        while(lo < hi){
            if(s[lo++] != s[hi--]){
                return false;
            }
        }
        return true;
    }
};