#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string base = "1";
        while(n > 1){
            base = say(std::move(base));
            --n;
        }
        return base;
    }

    std::string say(std::string&& base){
        std::string ret = "";
        
        int count = 0;
        char cur_c = base[0];

        for(auto& c : base){
            if(c == cur_c){
                ++count;
            }else{
                ret += std::to_string(count);
                ret.push_back(cur_c);
                count = 1;
                cur_c = c;
            }
        }
        ret += std::to_string(count);
        ret.push_back(cur_c);
        return ret;
    }
};
