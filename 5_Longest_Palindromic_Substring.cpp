#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL); 

    return 0;
}();

class Solution
{
public:
    int lo;
    int hi;

    std::string longestPalindrome(std::string s) 
    {
        const int n = s.length();
        this->lo = 0;
        this->hi = 0;
        for(int i = 0; i < n-1; ++i)
        {
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return s.substr(this->lo, this->hi-this->lo+1);
    }

    void expand(std::string& s, int i, int j)
    {
        if(i >=0 && j < s.length() && s[i] == s[j])
        {
            if(j - i > this->hi - this->lo)
            {
                this->lo = i;
                this->hi = j;
            }
            expand(s, i-1, j+1);
        }
    }
};



class Solution2//dp from Editorial
{
public:
    std::string longestPalindrome(std::string s) 
    {
        const int n = s.length();
        std::vector<std::vector<bool>> dp(n, std::vector<bool> (n, false));
        int lo = 0;
        int hi = 0;
        for(int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        for(int i = 0; i < n; ++i)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                lo = i;
                hi = i+1;
            }
        }

        for(int diff = 2; diff < n; ++diff)
        {
            for(int i = 0; i+diff < n; ++i)
            {
                int j = i + diff;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    lo = i;
                    hi = j;
                }

            }
        }

        return s.substr(lo, hi-lo+1);
    }
};



