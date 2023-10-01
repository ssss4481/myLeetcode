#include <vector>
using namespace std;

class Solution 
{
public:
    int count;
    int sum;

    void backTrack(vector<int>& nums, int& target, int i)
    {

        this->sum += nums[i];
        if(this->sum == target)
        {
            ++this->count;
        }
        else if(this->sum < target)
        {
            for(int j = 0; j < nums.size(); ++j)
            {
                backTrack(nums, target, j);
            }
        }
        this->sum -= nums[i];
        return;        
    }


    int combinationSum4(vector<int>& nums, int target)     
    {
        this->count = 0;
        this->sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            backTrack(nums, target, i);
        }
        return this->count;       
    }
};