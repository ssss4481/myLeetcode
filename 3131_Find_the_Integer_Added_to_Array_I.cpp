#include <vector>
#include <algorithm>

class Solution {
public:
    int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        return (*std::max_element(nums2.begin(), nums2.end()))- (*std::max_element(nums1.begin(), nums1.end()));
    }
};