
class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int prefix = 1;
        int suffix = (1+n)*n/2;
        if(prefix == suffix)
        {
            return 1;
        }

        for(int i = 2; i <= n; ++i)
        {
            prefix += i;
            suffix -= (i-1);
            if(prefix == suffix)
            {
                return i;
            }
        }

        return -1;        
    }
};