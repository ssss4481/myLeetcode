// The API isBadVersion is defined for you.

bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        long long lo = 1;
        long long hi = n;
        while(lo != hi)
        {
            long long mid = (lo+hi)/2;
            if(lo+1 == hi)
            {
                if(isBadVersion(lo))
                {
                    return static_cast<int>(lo);
                }
                else
                {
                    return static_cast<int>(hi);
                }
            }
            if(isBadVersion(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        }
        return static_cast<int>(lo);
    }
};