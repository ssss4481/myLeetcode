class Solution 
{
public:
    int numberOfMatches(int n) 
    {
        int ret = 0;
        while(n != 1)
        {
            bool odd = ((n&1) == 1);
            n /= 2;
            ret += n;
            if(odd)
            {
                ++n;
            }
        }
        return ret;
    }
};