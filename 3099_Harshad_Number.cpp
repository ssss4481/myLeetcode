class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int c = x;
        int div = 0;
        while(c != 0){
            div += (c % 10);
            c /= 10;
        }

        return x % div == 0 ? div : -1;
    }
};