#include <climits>
class Solution 
{
public:
    int reverse(int x) 
    {
        if(x == INT_MIN)
        {
            return 0;            
        }
        bool negative = x < 0;
        if(negative)
        {
            x = -x;
        }
        
        int rev = 0;
        while(x != 0)
        {
            
            for(int i = 1; i <= 3; ++i)
            {
                if(rev > INT_MAX-rev)
                {
                    return 0;
                }
                rev += rev;
            }
            if(rev > INT_MAX-(rev/4))
            {
                return 0;
            }
            rev += rev/4;
            rev += x%10;
            x /= 10;
        }

        if(negative)
        {
            rev = -rev;
        }

        return rev;
    }
};