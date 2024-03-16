#include <vector>
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
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                return nums1[i];
            }

            if(nums1[i] < nums2[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return -1;        
    }
};