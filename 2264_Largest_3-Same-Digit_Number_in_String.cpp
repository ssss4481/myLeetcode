#include <string>

class Solution 
{
public:
    std::string largestGoodInteger(std::string num) 
    {
        bool goodDigit[10] {false};
        int repeat = 0;
        char digit = num[0];
        for(auto& c: num)
        {
            if(c == digit)
            {
                ++repeat;
            }
            else
            {
                if(repeat >= 3)
                {
                    goodDigit[digit - '0'] = true;                    
                }
                repeat = 1;
                digit = c;
            }
        }
        if(repeat >= 3)
        {
            goodDigit[digit - '0'] = true;                    
        }        

        std::string ret = "";
        for(int i = 9; i >= 0; --i)
        {
            if(goodDigit[i])
            {
                char c = '0'+char(i);
                ret += c;
                ret += c;
                ret += c;
                break;
            }
        }

        return ret;        
    }
};