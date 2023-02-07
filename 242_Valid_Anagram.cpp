#include <string>
#include <vector>
using namespace std;


class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int sLength = s.length();
        if(sLength != t.length())
            return false;

        vector<int> zeros (26, 0);
        vector<int> sCount (26, 0);

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