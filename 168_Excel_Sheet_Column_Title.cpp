#include <string>
#include <iostream>
using namespace std;


class Solution 
{
public: 
    char intToC(int number)
    {
        return 'A' + char(number);
    }

    string convertToTitle(int columnNumber) 
    {        
        string ret = "";
        int r;
        int q;
        while(columnNumber--)
        {
            q = columnNumber / 26;
            r = columnNumber % 26;
            ret = intToC(r) + ret;
            columnNumber = std::move(q);
        }
  
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    string st = "abc";
    char c = 'a';
    st += c;
    cout << st << '\n';
    Solution b;
    cout << b.intToC(26) << '\n';
    return 0;
}
