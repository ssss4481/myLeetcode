#include <bitset>
#include <vector>
class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1){
            return x;
        }
        std::bitset<64> b{static_cast<unsigned long long>(x)};
        std::vector<int> zero_pos;
        for(int i = 0; i < 64; ++i){
            if(b[i] == 0){
                zero_pos.push_back(i);
            }
        }

        std::bitset<64> c{static_cast<unsigned long long>(n-1)};
        std::vector<int> one_pos;

        for(int i = 0; i < 64; ++i){
            if(c[i] == 1){
                one_pos.push_back(i);
            }
        }        
        
        for(int i = 0; i < one_pos.size(); ++i){
            b[zero_pos[one_pos[i]]] = 1;
        }

        return static_cast<long long>(b.to_ullong());
    }
};