#include <iostream>
#include <vector>
#include <algorithm>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::vector<int> sortByBits(std::vector<int>& arr) 
    {
        auto countBit = [](int num)
        {
            int bitCount = 0;
            while(num != 0)
            {
                num &= (num-1);
                ++bitCount;
            }
            return bitCount;
        };

        auto cmp = [&](int& a, int& b)
        {
            int aBitCount = countBit(a);
            int bBitCount = countBit(b);           

            if(aBitCount == bBitCount)
            {
                return a < b;
            }
            return aBitCount < bBitCount;
        };        
        std::sort(arr.begin(), arr.end(), cmp);     
        return arr;
    }
};