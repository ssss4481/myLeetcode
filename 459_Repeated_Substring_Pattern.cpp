#include <string>
using namespace std;

class Solution 
{
public:
    bool repeatedSubstringPattern(const string s) 
    {
        const int n = s.length();
        const int bound = n/2;
        for(int i = 1; i <= bound; ++i)
        {
            if(s.length() % i == 0)
            {
                string base = s.substr(0, i);
                const int baseLength = base.length();
                bool constructSuccessfully = true;
                for(int j = baseLength; j < n; j += baseLength)
                {
                    if(base != s.substr(j, i))
                    {
                        constructSuccessfully = false;
                        break;
                    }
                }
                if(constructSuccessfully)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};