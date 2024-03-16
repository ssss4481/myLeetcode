#include <vector>
#include <unordered_set>

class Solution 
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2(nums2.begin(), nums2.end());
        std::vector<int> ret;
        for(auto&n : set1)
        {
            if(set2.count(n))
            {
                ret.push_back(n);
            }
        }
        return ret;        
    }
};


class Solution2
{
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> set2;
        std::vector<int> ret;
        for(auto&n : nums2)
        {
            if(set1.count(n) == 1 && set2.count(n) == 0)
            {
                ret.push_back(n);
                set2.insert(n);
            }
        }
        return ret;        
    }
};