#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int magazineCount[26] = {0};
        for(auto& c : magazine){
            ++magazineCount[c-'a'];
        }
        for(auto&c : ransomNote){
            if(--magazineCount[c-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::vector<int> magazineArr(26, 0);

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
};



