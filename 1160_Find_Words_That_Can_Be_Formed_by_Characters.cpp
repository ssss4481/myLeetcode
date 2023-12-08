#include <vector>
#include <string>
#include <iostream>

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


    int countCharacters(std::vector<std::string>& words, std::string chars) 
    {
        auto count = [](std::string& word)
        {
            int* cCountArr = new int[26];
            for(auto& c: word)
            {
                ++cCountArr[c-'a'];                
            }
            return cCountArr;
        };

        auto baseArr = count(chars);
        int ret = 0;

        for(auto& word: words)
        {
            auto cCountArr = count(word);
            bool good = true;
            for(int i = 0; i < 26; ++i)
            {
                if(cCountArr[i] > baseArr[i])
                {
                    good = false;
                    break;
                }
            }
            if(good)
            {
                ret += word.length();
            }
            delete []cCountArr;
        }
        delete []baseArr;

        return ret;        
    }
};