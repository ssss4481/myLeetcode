#include <vector>
using namespace std;

class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        int max = 0;
        int sum = 0;
        for(auto& delta: gain)
        {
            sum += delta;
            if(sum > max)
            {
                max = sum;
            }
        }
        return max;        
    }
};