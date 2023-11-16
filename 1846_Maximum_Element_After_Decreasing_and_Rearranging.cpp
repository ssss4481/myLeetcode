#include <vector>
#include <algorithm>
#include <iostream>


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int maximumElementAfterDecrementingAndRearranging(std::vector<int>& arr) 
    {
        std::sort(arr.begin(), arr.end());
        if(arr[0] != 1)
        {
            arr[0] = 1;
        }

        for(int i = 1; i < arr.size(); ++i)
        {
            int diff = arr[i]-arr[i-1];
            if(diff > 1)
            {
                arr[i] -= (diff-1);
            }
        }

        return arr.back();        
    }
};