#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        int bit_count = 0;
        
        while(diff != 0){
            diff &= (diff-1);
            ++bit_count;
        }
        return bit_count;     
    }
};