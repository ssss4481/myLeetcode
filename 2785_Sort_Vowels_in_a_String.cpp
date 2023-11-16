#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

//static const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

static bool isvowel(char v) 
{
    return (0x208222>>(v&0x1f))&1;
}



class Solution//counting sort
{
public:
    std::string sortVowels(std::string s) 
    {
        int counts[10]{0};
        auto cToIdx = [](char& c)
        {
            int ret;
            switch (tolower(c))
            {
                case 'a':
                    ret = 0;
                    break;
                case 'e':
                    ret = 1;
                    break;
                case 'i':
                    ret = 2;
                    break;
                case 'o':
                    ret = 3;
                    break;
                case 'u':
                    ret = 4;
                    break;
            }
            if(c == tolower(c))
            {
                ret += 5;
            }
            return ret;
        };

        
        for(char& c : s)
        {
            if(isvowel(c))
            {
                ++counts[cToIdx(c)];
            }
        }

        char idxToC[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        int c = 0;
        for(int i = 0; i < s.length() && c < 10; ++i)
        {
            while (c < 10 && counts[c] == 0)
            {
                ++c;
            }
            if(isvowel(s[i]))
            {
                s[i] = idxToC[c];
                --counts[c];
            }            
        }
        return s;
    }
};

class Solution2//normal sort
{
public:
    std::string sortVowels(std::string s) 
    {
        std::vector<char> vowelArr;
        for(int i = 0; i < s.length(); ++i)
        {
            if(isvowel(s[i]))
            {
                vowelArr.push_back(s[i]);
            }            
        }

        std::sort(vowelArr.begin(), vowelArr.end());

        int j = 0;

        for(int i = 0; i < s.length() && j < vowelArr.size(); ++i)
        {
            if(isvowel(s[i]))
            {
                s[i] = vowelArr[j++];
            }    
        }
        return s;    
    }
};