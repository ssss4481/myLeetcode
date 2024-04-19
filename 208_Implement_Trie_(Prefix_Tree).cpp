#include <string>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


struct TrieNode{
    TrieNode* nextChar[26] = {nullptr};
    bool isWord;
    TrieNode(){
        isWord = false;
    }
};


inline int idx(char c){
    return int(c-'a');
}

class Trie {
private:
    TrieNode* firstChar[26] = {nullptr};

public:
    Trie(){}


    void insert(std::string word) {
        if(this->firstChar[idx(word[0])] == nullptr){
            this->firstChar[idx(word[0])] = new TrieNode();
        }
        auto pNode = this->firstChar[idx(word[0])];
        for(int i = 1; i < word.length(); ++i){
            if(pNode->nextChar[idx(word[i])] == nullptr){
                pNode->nextChar[idx(word[i])] = new TrieNode();
            }
            pNode = pNode->nextChar[idx(word[i])];
        }
        pNode->isWord = true;
    }

    bool search(std::string word) {
        auto pNode = this->firstChar[idx(word[0])];
        
        if(pNode == nullptr){
            return false;
        }
        
        for(int i = 1; i < word.length(); ++i){
            if(pNode->nextChar[idx(word[i])] == nullptr){
                return false;
            }
        
            pNode = pNode->nextChar[idx(word[i])];
        }
        return pNode->isWord;
    }
    
    bool startsWith(std::string prefix) {
        auto pNode = this->firstChar[idx(prefix[0])];
        if(pNode == nullptr){
            return false;
        }
        for(int i = 1; i < prefix.length(); ++i){
            if(pNode->nextChar[idx(prefix[i])] == nullptr){
                return false;
            }
            pNode = pNode->nextChar[idx(prefix[i])];
        }
        return true;
    }
};

