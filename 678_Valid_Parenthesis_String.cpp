#include <string>
#include <iostream>


class Solution 
{
public:
    bool checkValidString(std::string& s) 
    {
        int left = 0;
        int star = 0;
        for(auto& c : s)
        {
            if(c == '(')
            {
                ++left;
            }
            else if(c == '*')
            {
                ++star;
            }
            else
            {
                if(left > 0)
                {
                    --left;
                }
                else
                {
                    --star;
                    if(star < 0)
                    {
                        return false;
                    }                    
                }
            }
        }
        if(left > star)
        {
            return false;
        }

        left = 0;
        star = 0;

        int& right = left;

        for(int i = s.length()-1; i >= 0; --i)
        {
            if(s[i] == ')')
            {
                ++right;
            }
            else if(s[i] == '*')
            {
                ++star;
            }
            else
            {
                if(right > 0)
                {
                    --right;
                }
                else
                {
                    --star;
                    if(star < 0)
                    {
                        return false;
                    }                    
                }
            }            
        }

        if(right > star)
        {
            return false;
        }

        return true;
    }
};