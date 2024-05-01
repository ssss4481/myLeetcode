#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        const int target1 = (m+n+1)/2;
        const int target2 = (m+n+2)/2;
        return (findK(nums1, 0, nums2, 0, target1) + findK(nums1, 0, nums2, 0, target2))/2;
    }


    double findK(std::vector<int>& nums1, int i, std::vector<int>& nums2, int j, int k){
        if(i >= nums1.size()){
            return nums2[j+k-1];
        }
        if(j >= nums2.size()){
            return nums1[i+k-1];
        }

        if(k == 1){
            return std::min(nums1[i], nums2[j]);
        }

        int mid_val1 = (i + k/2 - 1 < nums1.size()) ? nums1[i + k/2 - 1] : INT_MAX;
        int mid_val2 = (j + k/2 - 1 < nums2.size()) ? nums2[j + k/2 - 1] : INT_MAX;

        if(mid_val1 < mid_val2){
            return findK(nums1, i + k / 2, nums2, j, k - k / 2);
        }else{
            return findK(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};