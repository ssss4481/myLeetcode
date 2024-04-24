#include <string>


class Solution {
public:
    std::string decodeString(std::string s) {
        int i = 0;
        return decode(s, i);
    }

    std::string decode(std::string& s, int& i){
        std::string ret = "";

        while(i < s.length()){
            if(isdigit(s[i])){
                int times = s[i] - '0';
                ++i;
                while(s[i] != '['){
                    times *= 10;
                    times += s[i] - '0';
                    ++i;
                }
                ++i;
                std::string sub_string = decode(s, i);
                while(times-- > 0){
                    ret += sub_string;
                }
            }else if(s[i] == ']'){
                ++i;
                break;
            }else{
                ret.push_back(s[i]);
                ++i;
            }
        }
        
        return ret;
    }
};









class Solution1 {
public:
    std::string decodeString(std::string s) {
        return recursiveDecode(s, 1, 0);
    }
    
    std::string recursiveDecode(std::string& s, int times, int start){
        std::string ret = "";
        for(int i = start; i < s.length(); ++i){
            if(isdigit(s[i])){
                int j = i+1;
                while(s[j] != '['){
                    ++j;
                }
                auto num_str = s.substr(i, j-i);
                ret += recursiveDecode(s, stoi(num_str), j+1);
                int left_count = 1;
                i = j+1;
                while(left_count > 0){
                    if(s[i] == '['){
                        ++left_count;
                    }else if(s[i] == ']'){
                        --left_count;
                    }
                    ++i;
                }
                --i;
            }else if(s[i] == ']'){
                break;
            }else{
                ret.push_back(s[i]);
            }
        }
        std::string base = ret;
        while(times-- > 1){
            ret += base;
        }
        return ret;
    }
};