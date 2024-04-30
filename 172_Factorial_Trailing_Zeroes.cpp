class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5;
        int five_count = 0;
        while(n >= base){            
            five_count += n/base;
            base *= 5;
        }
        return five_count;
    }
};