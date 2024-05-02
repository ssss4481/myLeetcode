#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        if(s.length() > 12 || s.length() < 4){
            return res;
        }
        std::string ip = "";
        backtracking(s, res, ip, 0, 1);

        return res;
    }

    void backtracking(std::string& s, std::vector<std::string>& res, std::string& ip, int idx, int part){
        if(idx >= s.size()){
            return;
        }

        if(part == 4){
            std::string byte = s.substr(idx);
            int val = stoi(byte);
            if(val > 255 || std::to_string(val).size() != (s.size()-idx)){
                return;
            }            
            res.push_back(ip+byte);
            return;
        }

        for(int i = 1; i <= 3; ++i){
            std::string byte = s.substr(idx, i);
            int val = stoi(byte);
            if(val > 255 || std::to_string(val).size() != i){
                continue;
            }
            ip += byte;
            ip += ".";
            backtracking(s, res, ip, idx+i, part+1);
            for(int c = 1; c <= i+1; ++c){
                ip.pop_back();
            }
        }
    }
};