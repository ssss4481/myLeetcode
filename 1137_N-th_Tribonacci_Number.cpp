#include <utility>

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }

        int t0 = 0;
        int t1 = 1;
        int t2 = 1;

        for(int i = 1; i <= n-2; ++i){
            int temp = t0+t1+t2;
            t0 = std::move(t1);
            t1 = std::move(t2);
            t2 = std::move(temp);
        }
        return t2;
    }
};