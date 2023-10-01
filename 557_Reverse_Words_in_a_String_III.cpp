#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    string reverseWords(string s) 
    {
        int lo = 0;
        int hi = 0;

        auto swapProcess = [&]()
        {
            while(lo < hi)
            {
                swap(s[lo++], s[hi--]);               
            }
        };

        for(int i = 0; i <= s.length(); ++i)
        {
            if(s[i] == ' ' || s[i] == '\0')
            {
                hi = i-1;
                swapProcess();
                lo = i+1;
            }
        }
        return s;        
    }
};







class Solution2 
{
public:
    void mySplit(const string &s, vector<string> &wordList)
    {
        string::size_type begin, end;

        begin = 0;
        end = s.find(' ');

        while(end != string::npos)
        {
            if(end - begin != 0)
            {
                wordList.push_back(s.substr(begin, end-begin));
            }
            begin = end + 1;
            end = s.find(' ', begin);
        }

        if(begin != s.length())
            wordList.push_back(s.substr(begin));
    }

    string reverseWords(string s)
    {
        vector<string> wordList;
        string ret = "";
        mySplit(s, wordList);

        for(auto& word : wordList)
        {
            reverse(word.begin(), word.end());
            ret += (word + " ");
        }


        return ret.substr(0, ret.length()-1);
    }
};







int main()
{
    string s = "123 321 456";
    vector<string> wordList;
    for(auto& word : wordList)
    {
        cout << word << "\n";
    }

    return 0;
}