#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    bool uniqueOccurrences(std::vector<int>& arr) 
    {
        std::unordered_map<int, int> hashMap;
        std::unordered_set<int> hashSet;
        for(auto& n: arr)
        {
            ++hashMap[n];
        }

        for(auto& p: hashMap)
        {
            if(hashSet.count(p.second) != 0)
            {
                return false;
            }
            hashSet.insert(p.second);
        }
        return true;        
    }
};