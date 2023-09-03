#include <vector>
#include <string>
using namespace std;

class Solution 
{
private:
    vector<vector<char>> startCharTable;


public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        if(digits.length() == 0)
        {
            return ret;
        }
        this->init();
        string combination = "";       
        this->backTracking(ret, digits, 0, combination);
        return ret;
    }

    void init()
    {
        this->startCharTable = vector<vector<char>> (10);
        char c = 'a';
        for(int i = 2; i <= 9; ++i)
        {
            if(i != 7 && i != 9)
            {
                for(int k = 1; k <= 3; ++k)
                {
                    this->startCharTable[i].push_back(c);
                    ++c;
                }
            }
            else
            {
                for(int k = 1; k <= 4; ++k)
                {
                    this->startCharTable[i].push_back(c);
                    ++c;
                }              
            }
        }
    }

    void backTracking(vector<string>& ret, string& digits, int idx, string& combination)
    {
        if(idx == digits.length())
        {
            ret.push_back(combination);
            return;
        }

        for(char& c: this->startCharTable[int(digits[idx]-'0')])
        {
            combination.push_back(c);
            this->backTracking(ret, digits, idx+1, combination);
            combination.pop_back();
        }
        return;
    }


};