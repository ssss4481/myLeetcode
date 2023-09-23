#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) 
    {
        this->dp = vector<vector<int>> (word1.length()+1, vector<int>(word2.length()+1, -1));        
        return word1toWord2(word1, word2, 0, 0);
    }

    int word1toWord2(string& word1, string& word2, int i, int j)
    {
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(i < word1.length() && j < word2.length())
        {

            int result;
            if(word1[i] == word2[j])
            {
                dp[i][j] = word1toWord2(word1, word2, i+1, j+1);
            }
            else
            {
                dp[i][j] = min({word1toWord2(word1, word2, i+1, j),
                            word1toWord2(word1, word2, i+1, j+1),
                            word1toWord2(word1, word2, i, j+1)})+1;
            }
        }
        else
        {
            int remainingWord1 = i - word1.length();
            int remainingWord2 = j - word2.length();
            dp[i][j] = abs(remainingWord1-remainingWord2);
        }
        return dp[i][j];
    }
};

class Solution2 //recursive brute force TLE
{
public:
    int minDistance(string word1, string word2) 
    {
        return word1toWord2(word1, word2, 0, 0);
    }

    int word1toWord2(string& word1, string& word2, int i, int j)
    {
        if(i < word1.length() && j < word2.length())
        {
            if(word1[i] == word2[j])
            {
                return word1toWord2(word1, word2, i+1, j+1);
            }
            return min({word1toWord2(word1, word2, i+1, j),
                        word1toWord2(word1, word2, i+1, j+1),
                        word1toWord2(word1, word2, i, j+1)})+1;
        }
        else
        {
            int remainingWord1 = i - word1.length();
            int remainingWord2 = j - word2.length();
            return abs(remainingWord1-remainingWord2);
        }
    }

};

class Solution3 //recursive brute force MLE
{
public:
    int minDistance(string word1, string word2) 
    {
        return word1toWord2(word1, word2, 0);
    }

    int word1toWord2(string word1, string word2, int i)
    {          
        if(i < word1.length() && i < word2.length())
        {
            if(word1[i] == word2[i])
            {
                return word1toWord2(word1, word2, i+1);
            }
            else
            {
                return min({word1toWord2(deleteChar(word1, i), word2, i), 
                word1toWord2(replaceChar(word1, i, word2[i]), word2, i+1),
                word1toWord2(addChar(word1, i, word2[i]), word2, i+1)})
                +1;
            }            
        }
        else
        {
            return abs(int(word2.length()) - int(word1.length()));
        }
    }

    string deleteChar(string word, int i)
    {
        return word.erase(i, 1);
    }

    string addChar(string word, int i, char c)
    {
        return word.insert(i, 1, c);
    }

    string replaceChar(string word, int i, char c)
    {
        word[i] = c;
        return word;
    }
};


string deleteChar(string word, int i)
{
    return word.erase(i, 1);
}

string addChar(string word, int i, char c)
{
    return word.insert(i, 1, c);
}

string replaceChar(string word, int i, char c)
{
    word[i] = c;
    return word;
}

int main(int argc, char const *argv[])
{
    string s = "capybara";
    cout << s << '\n';
    cout << deleteChar(s, 1) << '\n';
    cout << addChar(s, 1, 'A') << '\n';
    cout << replaceChar(s, 1, 'A') << '\n';
    return 0;
}
