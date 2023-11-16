#include <string>
#include <vector>
#include <iostream>

#define mod 1000000007
#define start 1LL
#define div 2LL

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int countHomogenous(std::string s) 
    {
        auto countHomoStr = [](long long int len)
        {
            return ((start+len)*len)/div;
        };

        long long int ret = 0;
        char currentC = s[0];
        int fragment = 1;

        for(int i = 1; i < s.length(); ++i)
        {
            if(s[i] != currentC)
            {
                ret = (ret+countHomoStr(fragment))%mod;
                fragment = 1;
                currentC = s[i];
            }
            else
            {
                ++fragment;
            }         
        }
        ret = (ret+countHomoStr(fragment))%mod;

        return int(ret);        
    }
};

#undef mod 1000000007
#undef start 1LL
#undef div 2LL