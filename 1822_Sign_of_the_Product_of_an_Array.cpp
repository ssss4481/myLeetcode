#include <vector>
using namespace std;

class Solution 
{
public:
    int arraySign(vector<int>& nums) 
    {
        bool positive;
        if(nums[0] > 0)
            positive = true;
        else if(nums[0] < 0)
            positive = false;
        else
            return 0;
        
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
                return 0;
            
            if((nums[i] > 0 && positive) || (nums[i] < 0 && !positive))
                positive = true;
            else
                positive = false;
        }
        return (positive ? 1 : -1);        
    }
};