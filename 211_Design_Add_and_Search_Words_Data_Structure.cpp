#include <vector>
#include <string>

class TrieNode
{
private:
    std::vector<TrieNode *> next;
    bool isword;

public:
    TrieNode()
    {
        this->next = std::vector<TrieNode *>(26, nullptr);
        this->isword = false;
    }

    void addWord(std::string &word, int i)
    {
        if (i == word.length())
        {
            this->isword = true;
            return;
        }

        if (next[word[i] - 'a'] == nullptr)
        {
            next[word[i] - 'a'] = new TrieNode();
        }
        next[word[i] - 'a']->addWord(word, i + 1);
    }

    bool search(std::string &word, int i)
    {
        if (i == word.length())
        {
            return this->isword;
        }
        if (word[i] == '.')
        {
            for (int j = 0; j < 26; ++j)
            {
                if (this->next[j] != nullptr && this->next[j]->search(word, i + 1))
                {
                    return true;
                }
            }
            return false;
        }

        if (this->next[word[i] - 'a'] != nullptr && this->next[word[i] - 'a']->search(word, i + 1))
        {
            return true;
        }
        return false;
    }
};

class WordDictionary
{
private:
    TrieNode *start;

public:
    WordDictionary()
    {
        this->start = new TrieNode();
    }

    void addWord(std::string word)
    {
        this->start->addWord(word, 0);
    }

    bool search(std::string word)
    {
        return this->start->search(word, 0);
    }
};
