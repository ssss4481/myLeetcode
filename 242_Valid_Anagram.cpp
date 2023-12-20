#include <string>
#include <iostream>
#include <vector>

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
    bool isAnagram(std::string s, std::string t)
    {
        int sLength = s.length();
        if(sLength != t.length())
        {
            return false;
        }

        int sCount[26] {0};

        for(int i = 0; i < sLength; ++i)
        {
            ++sCount[s[i]-'a'];
        }

        for(int i = 0; i < sLength; ++i)
        {
            --sCount[t[i]-'a'];
        }
        

        for(int i = 0; i < 26; ++i)
        {
            if(sCount[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution1
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int sLength = s.length();
        if(sLength != t.length())
            return false;

        std::vector<int> zeros (26, 0);
        std::vector<int> sCount (26, 0);

        for(int i = 0; i < sLength; ++i)
        {
            ++sCount[s[i]-'a'];
        }

        for(int i = 0; i < sLength; ++i)
        {
            --sCount[t[i]-'a'];
        }
        return zeros == sCount;
    }
};