#include <string>
#include <algorithm>

class Solution 
{
public:
    int maxScore(std::string s)
    {
        int totalZeroCount = 0;
        for(auto& c: s)
        {
            if(c == '0')
            {
                ++totalZeroCount;
            }
        }
        int totalOneCount = s.length()-totalZeroCount;
        int ret = 0;
        int leftZero = 0;
        for(int i = 0; i < s.length()-1; ++i)
        {
            if(s[i] == '0')
            {
                ++leftZero;
            }
            else
            {
                --totalOneCount;
            }
            ret = std::max(ret, leftZero + totalOneCount);
        }

        return ret;        
    }
};