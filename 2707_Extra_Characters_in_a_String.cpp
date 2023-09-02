#include <vector>
#include <string>

using namespace std;

int ch(char c)
{
    return int(c - 'a');
}

class Trie
{
public:
    Trie* pTrieArr[26];

    Trie()
    {
        memset(this->pTrieArr, nullptr, 26);
    }

    void insert(string& s)
    {
        this->insertHelper(s, 0);
    }

    void insertHelper(string& s, int depth)
    {
        if(depth == s.length())
        {
            return;
        }
        auto& pTrie = pTrieArr[ch(s[depth])];
        if(pTrie == nullptr)
        {
            pTrie = new Trie();
        }
        (*pTrie).insertHelper(s, depth+1);
    }


    bool hasString(string& s)
    {      
        return this->hasStringStartWithIdx(s, 0);
    }
    
    bool hasStringStartWithIdx(string& s, int idx)
    {
        if(idx == s.length())
        {
            return true;
        }

        auto& pTrie = pTrieArr[ch(s[idx])];
        if(pTrie != nullptr)
        {
            return (*pTrie).hasStringStartWithIdx(s, idx+1);        
        }
        return false;
    }

};


class Solution 
{
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {



        
    }
};
