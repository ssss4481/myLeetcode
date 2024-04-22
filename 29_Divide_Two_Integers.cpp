#include <climits>
#include <cmath>


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN){
            if(dividend == INT_MIN) {
                return 1;
            }else{
                return 0;
            }
        }

        bool dividend_positive = (dividend >= 0);
        bool divisor_positive = (divisor >= 0);
        divisor = abs(divisor);
        int preserved_q = 0;        
        if(dividend == INT_MIN){
            dividend += divisor;
            ++preserved_q;
        }
        dividend = abs(dividend);

        int q = quick_divide(dividend, divisor);
        
        if(q == INT_MAX && preserved_q > 0){
            if(dividend_positive ^ divisor_positive){
                return INT_MIN;
            }
            return INT_MAX;
        }

        q += preserved_q;
        if(dividend_positive ^ divisor_positive){
            return -q;
        }
        return q;
    }

    int quick_divide(int& dividend, int divisor){
        if(dividend < divisor){
            return 0;
        }
        int q = 0;
        if(divisor <= INT_MAX-divisor){
           q = quick_divide(dividend, divisor+divisor);
        }
        q += q;
        while(dividend >= divisor){
            dividend -= divisor;
            ++q;
        }
        return q;
    }


};