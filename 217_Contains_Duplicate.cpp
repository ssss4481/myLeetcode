#include <vector>
#include <unordered_set>

class Solution 
{
public:
    bool containsDuplicate(std::vector<int>& nums) 
    {
        std::unordered_set<int> hashSet;
        for(auto& n : nums)
        {
            if(hashSet.count(n) == 1)
            {
                return true;
            }
            hashSet.insert(n);
        }
        return false;
        
    }
};