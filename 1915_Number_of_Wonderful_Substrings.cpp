#include <string>
#include <vector>


class Solution {
public:
    long long wonderfulSubstrings(std::string word) {
        long long ans = 0;
        long long count[1024] = {0};
        count[0] = 1;
        int bits = 0;

        for(auto& c: word){
            bits ^= (1 << (c-'a'));
            ans += count[bits];
            for(int i = 0; i < 10; ++i){
                int temp_bit = bits ^ (1 << i);
                ans += count[temp_bit];
            }
            ++count[bits];
        }
        return ans;
    }
};