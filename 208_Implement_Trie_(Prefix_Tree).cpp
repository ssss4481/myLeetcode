#include <vector>
#include <string>
#include <iostream>
#include <string.h>
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
        this->pTrieArr = vector<Trie*>(26, nullptr);
    }


    Trie(bool end) 
    {
        this->end = end;      
        this->pTrieArr = vector<Trie*>(26, nullptr);
    }
    
    void insert(string word) 
    {
        insertHelper(word, 0);
    }

    void insertHelper(string& word, int idx)
    {
        auto& pTrie = this->pTrieArr[ch(word[idx])];

        if(idx < word.length()-1)
        {
            if(pTrie == nullptr)
            {
                pTrie = new Trie(false);            
            }
            pTrie->insertHelper(word, idx+1);
        }
        else if(idx == word.length()-1)
        {
            if(pTrie != nullptr)
            {
                pTrie->end = true;
            }
            else
            {
                pTrie = new Trie(true);
            }
        }
    }
    
    bool search(string word) 
    {
        return this->searchHelper(word, 0);
    }

    bool searchHelper(string& word, int idx) const
    {   
        auto& pTrie = this->pTrieArr[ch(word[idx])];
        if(pTrie == nullptr)
        {
            return false;
        }
        if(idx == word.length()-1)
        {
            return pTrie->end;
        }  
        return pTrie->searchHelper(word, idx+1);
    }
    
    bool startsWith(string prefix) 
    {
        return this->startsWithHelper(prefix, 0);      
    }

    bool startsWithHelper (string& prefix, int idx) const
    {    
        auto& pTrie = this->pTrieArr[ch(prefix[idx])];
        if(pTrie == nullptr)
        {
            return false;
        }               

        if(idx == prefix.length()-1)
        {
            return true;
        }
        return pTrie->startsWithHelper(prefix, idx+1);
    }
};



int main(int argc, char const *argv[])
{
    auto a = Trie();
    a.insert("abc");
    cout << a.search("ab") <<'\n';
    cout << a.search("abc") <<'\n';
    cout << a.search("abcd") <<'\n';
    a.insert("ab");
    cout << a.search("ab") <<'\n';



    
    return 0;
}
