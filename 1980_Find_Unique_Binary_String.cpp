#include <string>
#include <vector>
#include <unordered_set>
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
    int n;
    std::string ans;

    std::string findDifferentBinaryString(std::vector<std::string>& nums) 
    {
        this->n = nums.size();
        std::unordered_set<std::string> appearance(nums.begin(), nums.end());
        bool found = false;
        backTracking(appearance, 0, "", found);
        return this->ans;        
    }
    
    void backTracking(std::unordered_set<std::string>& appearance, int currentLength, std::string num, bool& found)
    {     
        if(found)
        {
            return;
        }

        if(currentLength == this->n)
        {
            if(appearance.count(num) == 0)
            {
                this->ans = num;
                found = true;
            }
            return;
        }
        
        backTracking(appearance, currentLength+1, num+"0", found);
        if(found)
        {
            return;
        }

        backTracking(appearance, currentLength+1, num+"1", found);
    }
};