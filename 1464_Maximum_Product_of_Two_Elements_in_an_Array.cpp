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
    int maxProduct(std::vector<int>& nums) 
    {
        int max_element = 0;
        int second_max_element = 0;
        for(auto& num: nums)
        {
            if(num > max_element)
            {
                second_max_element = max_element;
                max_element = num;
            }
            else if(num > second_max_element)
            {
                second_max_element = num;
            }
        }
        return (max_element-1)*(second_max_element-1);
    }
};

class Solution2
{
public:
    int maxProduct(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        return (*(nums.end()-1)-1)*(*(nums.end()-2)-1);
    }
};