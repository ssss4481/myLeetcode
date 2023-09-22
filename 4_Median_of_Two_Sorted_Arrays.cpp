#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() == 0 || nums2.size() == 0)
        {
            if(nums1.empty())
            {
                nums1.swap(nums2);
            }

            if(nums1.size() % 2)
            {
                return nums1[nums1.size()/2];
            }
            else
            {
                return double(nums1[nums1.size()/2-1]+ nums1[nums1.size()/2])/2;
            }

        }


        int totalSize = nums1.size() + nums2.size();
        int halfSize = totalSize/2;
        bool oddSize = totalSize % 2 ? true : false;
        if(oddSize)
        {
            ++halfSize;
        }
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int left = 0;
        int right = 0;
        
        auto adjust = [&]()->void
        {
            if(nums1[left] > nums2[right])
            {
                nums1.swap(nums2);
                swap(left, right);
            }
        };

        adjust();

        while(halfSize > 0)
        {
            auto leftUpperBound = upper_bound(nums1.begin(), nums1.end(), nums2[right]);
            int steps = int(leftUpperBound - nums1.begin()) - left;
            if(oddSize && steps >= halfSize)
            {
                return double(nums1[left+halfSize-1]);
            }
            else if(steps >= halfSize)
            {
                if(steps > halfSize)
                {
                    return double(nums1[left+halfSize-1]+nums1[left+halfSize])/2;
                }
                else
                {
                    return double(nums1[left+halfSize-1]+nums2[right])/2;
                }
            }
            else
            {
                left += steps;
                halfSize -= steps;
                adjust();
            }
        }

        return 0;        
    }
};