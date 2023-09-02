#include <string>
#include <vector>
using namespace std;

int ch(char c)
{
    return int(c - 'a');
}

class Trie
{
public:
    bool end;
    vector<Trie*> pTrieArr;

    Trie()
    {
        this->end = false;
        this->pTrieArr = vector<Trie*> (26, nullptr);
    }

    void insert(string word)
    {
        this->insertHelper(word, 0);
    }

    void insertHelper(string& s, int depth)
    {
        if(pTrieArr[ch(s[depth])] == nullptr)
        {
            pTrieArr[ch(s[depth])] = new Trie();
        }
        if(depth+1 == s.length())
        {          
            this->end = true;
            return;
        }        
        (*pTrieArr[ch(s[depth])]).insertHelper(s, depth+1);
    }

    bool search(string word) 
    {
        return this->hasString(word);
    }

    bool hasString(string& s)
    {      
        return this->hasStringStartWithIdx(s, 0);
    }
    
    bool hasStringStartWithIdx(string& s, int idx)
    {        
        if(this->pTrieArr[ch(s[idx])]!= nullptr)
        {
            if(idx == s.length()-1 && this->end)
            {
                return true;
            }
            return (*this->pTrieArr[ch(s[idx])]).hasStringStartWithIdx(s, idx+1);        
        }
        return false;
    }

    bool startsWith(string prefix) 
    {
        return startsWithHelper(prefix, 0);        
    }
    bool startsWithHelper(string& prefix, int idx)
    {
        if(pTrieArr[ch(prefix[idx])] != nullptr)
        {
            if(idx == prefix.length()-1)
            {
                return true;
            }
            return (*pTrieArr[ch(prefix[idx])]).startsWithHelper(prefix, idx+1);        
        }
        return false;
    }

};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */