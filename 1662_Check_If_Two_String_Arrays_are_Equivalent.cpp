#include <string>
#include <vector>

class Solution 
{
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) 
    {
        std::string w1 = "";
        std::string w2 = "";
        for(auto& word: word1)
        {
            w1 += word;
        }
        for(auto& word: word2)
        {
            w2 += word;
        }        

        return w1 == w2;                   
    }
};