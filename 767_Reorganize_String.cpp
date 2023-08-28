#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    string reorganizeString(string s) 
    {
        const int n = s.length();
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); ++i)
        {
            ++count[int(s[i]-'a')];
        }
        vector<char> chars(26);
        iota(chars.begin(), chars.end(), 0);        
        auto cmp = [&count](int a, int b){return count[a] > count[b];};        
        sort(chars.begin(), chars.end(), cmp);
                     
        int threshold = n/2;
        if(n%2)
        {
            ++threshold;
        }

        if(count[chars[0]] > threshold)
        {
            return "";
        }     

        int updatePos = 0;
        int i = 0; 
        while(i <= 25)
        {
            while(count[chars[i]] != 0)
            {               
                s[updatePos] = 'a'+chars[i];
                --count[chars[i]];
                updatePos += 2;
                if(updatePos >= n)
                {
                    if(updatePos%2 == 0)
                    {
                        updatePos = 1;
                    }
                    else
                    {
                        return s;
                    }
                }                    
            }
            ++i;               
        }       
        return s;
    }
};