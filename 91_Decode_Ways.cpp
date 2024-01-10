#include <string>
#include <iostream>
#include <vector>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();




class Solution1 
{
public:
    int ret;
    std::vector<int> dp;


    int numDecodings(std::string s) 
    {
        this->ret = 0;
        this->dp = std::vector<int> (s.length()+1, 0);
        dp[s.length()] = 1;
        backTracking(s, 0);
        return this->ret;        
    }

    int backTracking(std::string& s, int i)
    {   
        if(this->dp[i] != 0)
        {
            ret += this->dp[i];
            return this->dp[i];
        }
        if(s[i] == '0')
        {
            return 0;
        }
        this->dp[i] += backTracking(s, i+1);

        if(i+1 < s.length() && atoi(s.substr(i, 2).c_str()) <= 26)
        {
            this->dp[i] += backTracking(s, i+2);
        }
        return this->dp[i];
    }
};