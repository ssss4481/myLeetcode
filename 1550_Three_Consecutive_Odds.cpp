#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(auto& n : arr){
            if(n & 1){
                if(++count == 3){
                    return true;
                }
            }else{
                count = 0;
            }
        }
        return false;
    }
};