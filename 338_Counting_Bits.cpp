#include <vector>
using namespace std;


class Solution 
{
public:
    int count(int n)
    {
        int ret = 0;
        while (n != 0)
        {
            n &= (n-1);
            ++ret;            
        }

        return ret;      
    }

    vector<int> countBits(int n) 
    {
        vector<int> ret(n+1, 0);
        for(int i = 1; i <= n; ++i)
        {
            ret[i] = ret[i & (i-1)] + 1;
        }
        return ret;        
    }
}; 