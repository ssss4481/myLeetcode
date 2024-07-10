class Solution {
public:
    int passThePillow(int n, int time) {
        int q = time/(n-1);
        int r = time%(n-1);

        if((q & 1) == 1){
            return n-r;
        }else{
            return r;
        }
    }
};