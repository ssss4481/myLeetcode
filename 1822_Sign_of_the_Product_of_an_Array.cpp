#include <vector>
using namespace std;

class Solution 
{
public:
    int arraySign(vector<int>& nums) 
    {
        bool positive = true;

        for(int i = 0; i < nums.size(); ++i)
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