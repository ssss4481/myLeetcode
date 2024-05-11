class Solution {
public:
    long long flowerGame(int n, int m) {
        long long odd_in_n = (n/2);
        if(n%2 == 1){
            ++odd_in_n;
        }
        long long even_in_n = (n/2);

        long long odd_in_m = (m/2);
        if(m%2 == 1){
            ++odd_in_m;
        }
        long long even_in_m = (m/2);

        return odd_in_n * even_in_m + odd_in_m * even_in_n;
    }
};