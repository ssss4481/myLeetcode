#include <iostream>
#include <string>

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
    int lengthOfLastWord(std::string s) 
    {
        char str[s.length()+1];
        strcpy(str, s.c_str());
        char* pch;
        char* lastWord;
        pch = strtok (str," ");
        while (pch != NULL)
        {
            lastWord = pch;
            pch = strtok (NULL, " ");
        }       

        return static_cast<int>(strlen(lastWord));
    }
};



int main(int argc, char const *argv[])
{
    std::string s = "   fly me   to   the moon  ";
    char str[s.length()+1];
    strcpy(str, s.c_str());
    char* pch;
    pch = strtok (str," ,.-");
    char* lastWord;
    while (pch != NULL)
    {
        lastWord = pch;
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
    std::cout << static_cast<int>(strlen(lastWord)) << '\n';
    return 0;
}
