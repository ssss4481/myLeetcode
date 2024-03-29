#include <vector>
#include <string>
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
    std::string largestNumber(std::vector<int>& nums) 
    {
        auto cmp = [](std::string& a, std::string& b)
        {
            return a+b > b+a;
        };
        std::vector<std::string> sNums(nums.size());
        for(int i = 0; i < nums.size(); ++i)
        {
            sNums[i] = std::to_string(nums[i]);
        }

        std::sort(sNums.begin(), sNums.end(), cmp);

        std::string ret;
        for(auto& s : sNums)
        {
            ret += s;
        }
        if(ret[0] == '0')
        {
            return "0";
        }
        return ret;
    }
};