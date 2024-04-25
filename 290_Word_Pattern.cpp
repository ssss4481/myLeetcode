#include <string>
#include <unordered_map>
#include <vector>


class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {

        std::vector<int> space;
        space.push_back(-1);
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == ' '){
                space.push_back(i);
            }
        }
        space.push_back(s.length());
        
        if(space.size()-1 != pattern.length()){
            return false;
        }

        std::vector<std::string> map(26, "");
        std::unordered_map<std::string, char> string_to_p;

        for(int i = 1; i < space.size(); ++i){
            std::string word = s.substr(space[i-1]+1, space[i]-space[i-1]-1);
            if(map[pattern[i-1]-'a'] == ""){
                map[pattern[i-1]-'a'] = word;
            }else if(map[pattern[i-1]-'a'] != word){
                return false;
            }

            if(string_to_p.count(word) == 0){
                string_to_p[word] = pattern[i-1];
            }else if(string_to_p[word] != pattern[i-1]){
                return false;
            }
            
        }
        
        return true;
    }
};