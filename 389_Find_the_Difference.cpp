#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Solution 
{
public:
    char findTheDifference(string s, string t) 
    {
        vector<int> count(26, 0);
        for(auto& c:s)
        {
            ++count[int(c-'a')];
        }

        for(auto& c:t)
        {            
            if(--count[int(c-'a')] < 0)
            {
                return c;
            }
        }
        return 0;        
    }
};


class Solution2
{
public:
    char findTheDifference(string s, string t) 
    {
        long long int Sum = 0;
        return char(accumulate(t.begin(), t.end(), Sum) - accumulate(s.begin(), s.end(), Sum));        
    }
};



int main(int argc, char const *argv[])
{
    string a = "abcd";
    string b = "abcde";
    cout << Solution2().findTheDifference(a, b);

    return 0;
}
