#include <vector>
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
    int findSpecialInteger(std::vector<int>& arr) 
    {
        const int quarter = arr.size()/4;

        for(int i = 0; i < arr.size()-quarter; ++i)
        {
            if(arr[i] == arr[i+quarter])
            {
                return arr[i];
            }
        }
        return -1;        
    }
};