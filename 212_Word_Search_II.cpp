#include <vector>
#include <string>

class TrieNode{
public:
    TrieNode* next[26];
    std::string word;
    TrieNode(){    
        for(int i = 0; i < 26; ++i){
            next[i] = nullptr;
        }
        this->word = "";
    }
};


class Solution {
public:
    int m;
    int n;
    std::vector<std::string> ret;

    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words){
        this->m = board.size();
        this->n = board[0].size();

        auto root = new TrieNode();

        for(const auto& word: words){
            auto current = root;
            for(int i = 0; i < word.length(); ++i){
                if(current->next[word[i]-'a'] == nullptr)
                {
                    current->next[word[i]-'a'] = new TrieNode();
                }
                current = current->next[word[i]-'a'];
            }
            current->word = word;
        }

        for(int i = 0; i < this->m; ++i){
            for(int j = 0; j < this->n; ++j){
                DFS(board, i, j, root);
            }
        }
        return this->ret;
    }

    void DFS(std::vector<std::vector<char>>& board, int i, int j, TrieNode* current){
        if(board[i][j] == '#'){
            return;
        }

        auto next = current->next[board[i][j]-'a'];

        if(next == nullptr){
            return;
        }

        if(next->word != ""){
            this->ret.push_back(next->word);
            next->word = "";
        }

        char c = board[i][j];
        board[i][j] = '#';
        if(i > 0){
            DFS(board, i-1, j, next);
        }
        if(i < this->m-1){
            DFS(board, i+1, j, next);
        }
        if(j > 0){
            DFS(board, i, j-1, next);
        }
        if(j < this->n-1){
            DFS(board, i, j+1, next);
        }
        board[i][j] = c;
    }
};