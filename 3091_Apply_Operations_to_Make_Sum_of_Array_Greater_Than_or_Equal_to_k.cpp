#include <bits/stdc++.h>

class Solution {
public:

    int minOperations(int k) {
        if(k == 1){
            return 0;
        }
        int ops = k-1;

        for(int i = 1; i < k; ++i){
            int base = i+1;
            int sum = base;
            int currentOP = i + (k-sum)/base;
            if((k-sum) % base > 0){
                ++currentOP;
            }
            ops = std::min(ops, currentOP);
        }
        return ops;
    }


};