#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string s = to_string(x);
        int lo = 0;
        int hi = s.length()-1;
        while(lo < hi)
        {
            if(s[lo++] != s[hi--])
            {
                return false;
            }          
        }
        return true;        
    }
};