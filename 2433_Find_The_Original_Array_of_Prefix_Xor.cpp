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
    std::vector<int> findArray(std::vector<int>& pref) 
    {
        for(int i = pref.size()-1; i > 0; --i)
        {
            pref[i] ^= pref[i-1];
        }
        return pref;        
    }
};