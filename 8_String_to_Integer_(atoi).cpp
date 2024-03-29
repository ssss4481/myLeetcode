#include <string>
#include <iostream>

class Solution 
{
public:
    int myAtoi(std::string s) 
    {
        bool readDigit = false;
        bool readPN = false;
        bool positive = true;       
        int i = 0; 
        int lo = -1;
        while (i < s.length())
        {
            if(!readDigit && !readPN)
            {
                if(!isdigit(s[i]))
                {
                    if(s[i] == '+')
                    {
                        readPN = true;
                    }
                    else if(s[i] == '-')
                    {
                        readPN = true;
                        positive = false;
                    }
                    else if(s[i] != ' ')
                    {
                        break;
                    }
                }
                else
                {
                    readDigit = true;
                    lo = i;
                }
            }
            else
            {
                if(!readDigit && isdigit(s[i]))
                {
                    lo = i;
                    readDigit = true;
                }
                else if(!isdigit(s[i]))
                {
                    break;
                }
            }
            ++i;
        }

        if(lo == -1)
        {
            return 0;
        }
        std::string trim = s.substr(lo, i-lo);

        if(positive && atoll(trim.c_str()) >= INT_MAX)
        {
            return INT_MAX;
        }

        if(!positive && -atoll(trim.c_str()) <= INT_MIN)
        {
            return INT_MIN;
        }


        int ret = atoi(trim.c_str());
        return positive ? ret : -ret;
    }
};