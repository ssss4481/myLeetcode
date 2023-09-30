#include <vector>
#include <iostream>
using namespace std;

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    bool isMonotonic(vector<int>& nums) 
    {
        const int n = nums.size();
        
        if(n == 1)
        {
            return true;
        }

        auto check = [&](auto compare)
        {
            for(int i = 1; i < n; ++i)
            {
                if(compare(nums[i-1], nums[i]))
                {
                    return false;
                }
            }
            return true;
        };

        if(nums.front() < nums.back())
        {
            return check([](int& a, int& b){return a > b;});
        }
        else if(nums.front() == nums.back())
        {
            return check([](int& a, int& b){return a != b;});
        }
        else
        {
            return check([](int& a, int& b){return a < b;});
        }
    }
};

/*
        auto check = [&](auto compare)
        {
            for(int i = 1; i < n; ++i)
            {
                if(compare(nums[i-1], nums[i]))
                {
                    return false;
                }
            }
            return true;
        };

        can also be:

        auto check = [&](bool (*compare)(int&, int&))
        {
            for(int i = 1; i < n; ++i)
            {
                if(compare(nums[i-1], nums[i]))
                {
                    return false;
                }
            }
            return true;
        };        
*/