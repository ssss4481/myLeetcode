#include <vector>
#include <iostream>
#include <cmath>
static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int lo = 0;
        int hi = sqrt(c);

        long l = 0;
        long h = hi*hi;

        while(lo <= hi){
            long sum = l + h;
            if(sum == c){
                return true;
            }

            if(sum < c){
                ++lo;
                l = lo*lo;
            }else{
                --hi;
                h = hi*hi;
            }
        }
        return false;
    }
};


class Solution1 {
public:
    bool judgeSquareSum(int c) {
        long b = 1;
        vector<long> candidates = {0}; 
        while(b*b <= c){
            candidates.push_back(static_cast<int>(b*b));
            ++b;
        }
        int lo = 0;
        int hi = candidates.size()-1;

        while(lo <= hi){
            long sum = candidates[lo]+candidates[hi];
            if(sum == c){
                return true;
            }

            if(sum < c){
                ++lo;
            }else{
                --hi;
            }
        }

        return false;
    }
};