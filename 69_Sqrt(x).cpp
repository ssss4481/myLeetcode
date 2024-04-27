class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0;
        long long hi = x;

        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            long long sq1 = mid*mid;
            long long sq2 = (mid+1)*(mid+1);
            if(sq1 <= x && sq2 > x){
                return mid;
            }
            if(sq1 < x){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return 0;

    }
};