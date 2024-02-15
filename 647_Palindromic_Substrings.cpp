#include <string>

class Solution 
{
public:
    int ret;

    int countSubstrings(std::string s) 
    {
        this->ret = s.length();

        for(int i = 0; i < s.length(); ++i)
        {
            baseOnSize1(i, s);
            baseOnSize2(i, s);
        }       

        return this->ret; 
    }

    void baseOnSize1(int mIdx, std::string& s)
    {
        int lIdx = mIdx-1;
        int rIdx = mIdx+1;
        this->expansion(lIdx, rIdx, s);
    }

    void baseOnSize2(int lIdx, std::string& s)
    {  
        int rIdx = lIdx+1;
        this->expansion(lIdx, rIdx, s);
    }

    void expansion(int& lIdx, int& rIdx, std::string& s)
    {
        while(lIdx >= 0 && rIdx < s.length())
        {
            if(s[lIdx--] != s[rIdx++])
            {
                break;
            }
            ++ret;
        }
    }
};