#include <vector>
#include <algorithm>

using namespace std;

//TLE sol
class Solution {
public:
    
    int recursiveSolve(vector<int>& nums, vector<int>& multipliers, int lo, int hi, int idx, const int& m)
    {
        if(idx == m)
        {
            return max(multipliers[idx]*nums[lo], multipliers[idx]*nums[hi]);
        }
        
        return max(multipliers[idx]*nums[lo] + recursiveSolve(nums, multipliers, lo+1, hi, idx+1, m), multipliers[idx]*nums[hi] + recursiveSolve(nums, multipliers, lo, hi-1, idx+1, m));

    }
    
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int lo = 0;
        int hi = nums.size()-1;
        int idx = 0;
        int m = multipliers.size()-1;

        return recursiveSolve(nums, multipliers, lo, hi, idx, m);
        
    }
};



int main()
{
    return 0;
}