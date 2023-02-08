#include <algorithm>
#include <vector>


using namespace std;

class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int step = 0;
        int location = 0;
        int cut = 0;
        int goal = nums.size()-1;

        while (location != goal)
        {
            int farthest = location + nums[location];
            int nextCut = farthest;
            int nextLocation = farthest;
            if(farthest >= goal)
            {
                nextLocation = goal;
            }
            else
            {                
                for(int i = cut+1; i <= location + nums[location] && i < nums.size(); ++i)
                {
                    if(i + nums[i] > farthest)
                    {
                        farthest = i + nums[i];
                        nextLocation = i;
                    }
                }                       
            }
            location = nextLocation;
            cut = nextCut;
            ++step;
        }    
        return step;
    }
};