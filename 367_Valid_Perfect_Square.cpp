#include <iostream>

class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        for(int i = 1; i <= num; ++i)
        {
            int square = i*i;
            if(square == num)
            {
                return true;
            }
            
            if(square > num)
            {
                break;
            }
        }
        return false;        
    }
};