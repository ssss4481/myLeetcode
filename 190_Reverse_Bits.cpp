class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t b = 1;
        for(int i = 0; i < 31; ++i){
            if(n & b == 1){
                ++ret;
            }
            ret <<= 1;
            n >>= 1;
        }
        if(n != 0){
            ++ret;
        }

        return ret;
    }
};