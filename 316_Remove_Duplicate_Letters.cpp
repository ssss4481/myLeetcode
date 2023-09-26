#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string removeDuplicateLetters(string s) 
    {
        const int n = s.length();
        vector<int> last(26, 0);
        for(int i = 0; i < n; ++i)
        {
            last[int(s[i]-'a')] = i;            
        }
        vector<char> cStack;
        vector<char> included(26, 0);
        for(int i = 0; i < n; ++i)
        {
            if(cStack.empty() || included[int(s[i]-'a')] == 0)
            {
                while(!cStack.empty() && s[i] < cStack.back() && i < last[int(cStack.back()-'a')])
                {
                    cStack.pop_back();
                    included[int(cStack.back()-'a')] = 0;
                }
                cStack.push_back(s[i]);
                included[int(s[i]-'a')] = 1;
            }
        }        

        string ret(cStack.begin(), cStack.end());
        return ret;        
    }
};


int main(int argc, char const *argv[])
{
    string a = "bc";
    a[1] = 's';
    cout << a << '\n';
    return 0;
}
