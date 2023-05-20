#include <string>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u';
    }

    int maxVowels(string s, int k) 
    {
        //unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max = 0;
        int current = 0;
        for(int i = 0; i < k ; ++i)
        {
            current += this->isVowel(s[i]);
        }

        if(current > max)
            max = current;


        for(int i = k; i < s.length(); ++i)
        {
            current += this->isVowel(s[i]);
            current -= this->isVowel(s[i-k]);
            if(current > max)
                max = current;            
        }

        return max;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
