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
    int maxFrequencyElements(std::vector<int>& nums) 
    {
        int table[101] = {0};
        int maxF = 0;
        for(auto& n: nums)
        {            
            maxF = std::max(++table[n], maxF);
        }  
        int ret = 0;
        for(int i = 1; i < 101; ++i)
        {
            if(table[i] == maxF)
            {
                ret += maxF;
            }
        }
        return ret;
    }
};



class Solution 
{
public:
    int maxFrequencyElements(std::vector<int>& nums) 
    {
        std::vector<int> table(101, 0);
        for(auto& n: nums)
        {
            ++table[n];
        }
        int f = *std::max_element(table.begin(), table.end());        
        int ret = 0;
        for(auto& n: table)
        {
            if(n == f)
            {
                ret += f;
            }
        }
        return ret;
    }
};

