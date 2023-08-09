#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution 
{
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size()-1] - nums[0];

        while(left < right - 1)
        {
            int mid = left + (right-left)/2;
            if(countValidPairsint(nums, mid) >= p)
            {
                right = mid;                
            }
            else
            {
                left = mid;
            }
        }

        if(countValidPairsint(nums, left) >= p)
        {
            return left;
        }
        else
        {
            return right;
        }
    }

    int countValidPairsint(vector<int>& nums, int threshold)
    {      
        int count = 0;        
        for(int i = 0; i < nums.size()-1; ++i)
        {  
            if(nums[i+1]-nums[i] <= threshold)
            {
                ++count;
                ++i;
            }
        }
        return count;
    }
};