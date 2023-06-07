#include <vector>
#include <algorithm>
using namespace std;


class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        const int d = arr[1] - arr[0];
        const int n = arr.size();

        sort(arr.begin(), arr.end());

        for(int i = 2; i < n; ++i)
        {
            if(arr[i] - arr[i-1] != d)
                return false;
        }
        
        return true;        
    }
};