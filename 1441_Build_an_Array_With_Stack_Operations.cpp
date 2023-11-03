#include <vector>
#include <string>
#include <iostream>

class Solution 
{
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) 
    {
        std::vector<std::string> ret;
        int ti = 0;
        for(int i = 1; i <= n && ti < target.size(); ++i)
        {           
           if(target[ti] == i) 
           {
                ret.push_back("Push");
                ++ti;
           }
           else
           {
                ret.push_back("Push");
                ret.push_back("Pop");
           }           
        }
        return ret;        
    }
};