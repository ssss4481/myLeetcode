#include <vector>
#include <string>
#include <sstream>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class TrieNode{
private:
    TrieNode* next[26];
    string word;    
public:
    TrieNode(){
        for(int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
        word = "";
    }

    void addWord(const string& s, int index){
        if(index == s.size()){
            word = s;
            return;
        }
        auto pNode = new TrieNode();
        next[s[index]-'a'] = pNode;
        pNode->addWord(s, index+1);
    }

    string findWord(const string& s, int index){
        if(word != ""){
            return word;
        }
        if(index == s.size()){
            return "";
        }
        auto pNode = next[s[index]-'a'];
        if(pNode == nullptr){
            return this->word;
        }
        return pNode->findWord(s, index+1);
    }
};

class Trie{
private:
    TrieNode* start[26];

public:
    Trie(){
        for(int i = 0; i < 26; ++i){
            start[i] = nullptr;
        }
    }

    bool may_be_replaced(const string& s){
        return start[s[0]-'a'] != nullptr;
    }

    void addWord(const string& s){
        if(start[s[0]-'a'] == nullptr){
            start[s[0]-'a'] = new TrieNode();
        }
        start[s[0]-'a']->addWord(s, 1);
    }

    string getReplaceWord(const string& s){
        if(may_be_replaced(s)){
            string result = start[s[0]-'a']->findWord(s, 1);
            if(result != ""){
                return result;
            }
        }
        return s;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie = Trie();
        for(auto& s: dictionary){
            trie.addWord(s);
        }
        string output = "";
        stringstream ss(sentence);
        string s;
        while(ss >> s){
            output += trie.getReplaceWord(s);
            output.push_back(' ');
        }
        output.pop_back();
        return output;
    }
};