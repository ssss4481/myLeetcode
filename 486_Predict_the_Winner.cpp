#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int play(int player, int start, int end,vector<int>& nums)
    {
        if(start == end)
        {
            return nums[start];
        }

        if(player)
        {
            return min(play(0, start+1, end, nums), play(0, start, end-1, nums));
        }
        else
        {
            return max(play(1, start+1, end, nums)+nums[start], play(1, start, end-1, nums)+nums[end]);
        }
    }


    bool PredictTheWinner(vector<int>& nums) 
    {
        int i = 0;
        int j = nums.size()-1;
        int sum = accumulate(nums.begin(), nums.end(), 0) ;
        int res = play(0, i, j, nums);        
        return res >= sum - res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
