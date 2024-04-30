#include <deque>

class Solution {
public:
    int lastRemaining(int n) {
        return ans(n, true);
    }
    int ans(int n, bool toRight){
        if(n == 1) {
            return 1;
        }
        if(n == 2){
            if(toRight){
                return 2;
            }else{
                return 1;
            }
        }
        if(n == 3){
            return 2;
        }

        if(toRight || n%2 == 1){
            return 2*ans(n/2, !toRight);
        }else{
            return 2*ans(n/2, !toRight)-1;
        }
    }
};


class Solution1 {//?
public:
    int lastRemaining(int n) {
        if(n % 2 == 1){
            --n;
        }
        int step = 0;
        bool toRight = true;
        while(n > 3){   
            ++step;
            if(toRight){
                n /= 2;
                toRight = false;
            }else{
                n /= 2;
                ++n;
                toRight = true;
            }
        }
        int base;
        if(n == 3){
            base = 2;
        }else if(n == 2){
            if(toRight){
                base = 2;
            }else{
                base = 1;
            }
        }

        while(step > 0){
            if(toRight){
                --base;
                base *= 2;
                toRight = false;
            }else{
                base *= 2;
                toRight = true;
            }
            --step;
        }

        return base;
    }
};



class Solution {
public:
    int lastRemaining(int n) {//MLE
        std::deque<int> dq;
        for(int i = 1; i <= n; ++i){
            dq.push_back(i);
        }
        bool left_to_right = true;
        while(dq.size() > 1){
            std::deque<int> dq2;
            if(left_to_right){
                while(!dq.empty()){
                    dq.pop_front();
                    if(!dq.empty()){
                        dq2.push_back(dq.front());
                        dq.pop_front();
                    }
                }
                left_to_right = false;
            }else{
                while(!dq.empty()){
                    dq.pop_back();
                    if(!dq.empty()){
                        dq2.push_front(dq.back());
                        dq.pop_back();
                    }
                }
                left_to_right = true;
            }
            dq.swap(dq2);
        }
        return dq.front();
    }
};