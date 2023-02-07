#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        //give a value to char by the order info.
        map<char, int> charToValue;
        for(int i = 0; i < order.length(); ++i)
        {
            charToValue[order[i]] = i;
        }
        for(int i = 0; i < words.size()-1; ++i)
        {
            string& before = words[i];
            string& after = words[i+1];
            int j = 0;
            int limit = min(before.length(), after.length());
            while(j < limit)
            {
                if(charToValue[before[j]] < charToValue[after[j]])
                    break;
                else if(charToValue[before[j]] > charToValue[after[j]])
                    return false;
                ++j;
            }
            if(j == limit && before.length() > limit)
                return false;
        }
        return true;
    }
};




int main()
{
    vector<string> words1 = {"hello","leetcode"};
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";

    Solution s = Solution();
    cout << s.isAlienSorted(words1, order1) << "\n";



    return 0;
}