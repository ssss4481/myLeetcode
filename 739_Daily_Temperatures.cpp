#include <vector>
class Solution 
{
public:

    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) 
    {
        std::vector<int> ret(temperatures.size()+1, temperatures.size());

        for(int i = temperatures.size()-1; i > 0; --i)
        {
            temperatures[i] = temperatures[i]-temperatures[i-1];
        }
        temperatures[0] = 0;
        


        
    }
};