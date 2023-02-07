#include<vector>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ret;

        if(s.length() < p.length())
            return ret;


        vector<int> pCount (26, 0);
        vector<int> sCount(26, 0);

        for(int i = 0; i < p.length(); ++i)
        {
            ++pCount[int(p[i]-'a')];
        }

        for(int i = 0; i < p.length(); ++i)
        {
            ++sCount[int(s[i]-'a')];
        }

        int begin = 0;
        int last = p.length()-1;

        while(true)
        {
            if(pCount == sCount)
            {
                ret.push_back(begin);
            }
            --sCount[int(s[begin]-'a')];
            ++begin;
            ++last;
            if(last < s.length())
            {
                ++sCount[int(s[last]-'a')];
            }
            else
            {
                break;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
