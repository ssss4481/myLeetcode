#include <vector>
#include <algorithm>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) 
    {
        auto lo = std::lower_bound(nums.begin(), nums.end(), target);
        if (lo == nums.end() || *lo != target)
        {
            return {-1, -1};
        }
        auto hi = std::upper_bound(nums.begin(), nums.end(), target);    
        return {int(lo-nums.begin()), int(hi-nums.begin())-1};        
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> v{0, 1, 2, 2, 2, 3, 4};
    std::cout << (std::lower_bound(v.begin(), v.end(), 2)-v.begin()) << '\n';
    std::cout << (std::upper_bound(v.begin(), v.end(), 4)-v.begin()) << '\n';


    



    return 0;
}
