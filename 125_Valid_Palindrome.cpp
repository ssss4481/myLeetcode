#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> charArr(s.length());
        int putIdx = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(isalnum(s[i]) != 0)
            {
                charArr[putIdx] = char(tolower(s[i]));
                ++putIdx;
            }
        }

        int lo = 0;
        int hi = putIdx-1;

        while(lo < hi)
        {
            if(charArr[lo] != charArr[hi])
                return false;
            ++lo;
            --hi;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    char a = 'A';
    char k = ',';
    string bc = "BC";
    cout << char(tolower(a)) << "\n";
    cout << isalpha(a) << "\n";
    cout << isalpha(k) << "\n";



    return 0;
}
