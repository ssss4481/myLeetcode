#include <string>
#include <vector>
#include <algorithm>

class Solution 
{
public:
    int maxDepth(std::string s) 
    {
        int depth = 0;
        int left = 0;
        for(auto& c: s)
        {
            if(c == '(')
            {
                ++left;
            }
            else if(c == ')')
            {
                depth = std::max(depth, left);
                --left;
            }
        }
        return depth;
    }
};