#include <vector>
#include <climits>
using namespace std;

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        const int arrSize = m + n;
        vector<int> nums1Copy = nums1;
        nums2.push_back(INT_MAX);
        int i = 0;
        int j = 0;
        int k = 0;
        while(k < arrSize)
        {
            if(i < m && nums1Copy[i] <= nums2[j])
            {
                nums1[k] = nums1Copy[i];
                ++i;
            }
            else
            {
                nums1[k] = nums2[j];
                ++j;
            }
            ++k;
        }        
    }
};