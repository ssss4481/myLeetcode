#include <vector>

class Solution 
{
public:
    int majorityElement(std::vector<int>& nums) 
    {
        int majority;
        int count = 0;
        for(auto& n: nums)
        {
            if(count == 0)
            {
                majority = n;
            }

            if(n == majority)            
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        return majority;        
    }
};