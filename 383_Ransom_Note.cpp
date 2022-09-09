#include <iostream>
#include <vector>
#include <string>

using namespace std;



bool canConstruct(string ransomNote, string magazine)
{
    //vector<int> ransomArr(26, 0);
    vector<int> magazineArr(26, 0);

    for(int i = 0; i < magazine.length(); ++i)
    {
        ++magazineArr[int(magazine[i] - 'a')];
    }

    for(int i = 0; i < ransomNote.length(); ++i)
    {
        --magazineArr[int(ransomNote[i] - 'a')];
    }

    for(int i = 0; i < 26; ++i)
    {
        if(magazineArr[i] < 0)
        {
            return false;
        }
    }
    return true;
}



int main()
{


    cout << canConstruct("aa", "ab") << endl;
    cout << canConstruct("aa", "aab") << endl;
    cout << canConstruct("a", "b") << endl;




    return 0;
}