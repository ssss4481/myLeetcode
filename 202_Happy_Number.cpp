#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        while(set.count(n) == 0){
            set.insert(n);
            int sum = 0;
            while(n != 0){
                int d = n%10;
                sum += d*d;
                n /= 10;
            }
            if(sum == 1){
                return true;
            }
            n = sum;
        }
        return false;
    }
};