#include <vector>

using namespace std;

//82,288,250,131,354,261 -> 4

class Solution 
{
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        const int n = nums.size();
        long long ret = 0;
        if(n == 1)
        {
            return ret;
        }
        int i = n-1;
        while(i > 0)
        {
            int& hi = nums[i];
            int& lo = nums[i-1];            
            if(lo > hi)
            {                
                if(lo % hi == 0)
                {
                    ret += lo/hi-1;
                    lo = hi;
                }
                else
                {
                    ret += lo/hi;
                    lo /= (lo/hi + 1);
                }                
            }
            --i;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
