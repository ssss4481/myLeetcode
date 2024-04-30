#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findTheLongestSubstring(std::string s) {
        auto charToBitMask = [](char c){
            if(c == 'a'){
                return 1;
            }
            if(c == 'e'){
                return 2;
            }
            if(c == 'i'){
                return 4;
            }
            if(c == 'o'){
                return 8;
            }
            if(c == 'u'){
                return 16;
            }
            return 0;
        };
        
        int ans = 0;
        int bits = 0;
        std::vector<int> base(32, -2);
        base[0] = -1;

        for(int i = 0; i < s.length(); ++i){
            bits ^= charToBitMask(s[i]);
            if(base[bits] == -2){
                base[bits] = i;
            }else{
                ans = std::max(ans, i - base[bits]);
            }
        }
        return ans;
    }
};