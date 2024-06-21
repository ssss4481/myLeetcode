#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int n = customers.size();

        //init sliding window        
        int grumpyAndSatisfied = 0;
        int nonGrumpyAndSatisfied = 0;
        int hi = 0;
        for(; hi < minutes; ++hi){
            if(grumpy[hi] == 1){
                grumpyAndSatisfied += customers[hi];
            }else{
                nonGrumpyAndSatisfied += customers[hi];
            }
        }
        //process silding window
        int bestGAS = grumpyAndSatisfied;
        int lo = 0;
        for(; hi < n; ++hi, ++lo){
            if(grumpy[lo] == 1){
                grumpyAndSatisfied -= customers[lo];
            }
            if(grumpy[hi] == 1){
                grumpyAndSatisfied += customers[hi];
            }else{
                nonGrumpyAndSatisfied += customers[hi];
            }
            bestGAS = max(bestGAS, grumpyAndSatisfied);
        }

        return nonGrumpyAndSatisfied + bestGAS;
    }
};