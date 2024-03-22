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
    void rotate(std::vector<int>& nums, int k) 
    {
        const int mod = nums.size();
        k %= mod;

        if(k == 0)
        {
            return;
        }
        
        int next;
        int temp;

        next = k;
        temp = nums[0]; 
        int base = 1;

        int start = next;       
        for(int i = 0; i < nums.size(); ++i)
        {
            std::swap(temp, nums[next]);
            next = (next+k) % mod;
            if(next == start)
            {
                next = (next+1)%mod;
                temp = nums[base++];
                start = next;
            }            
        }   
    }
};