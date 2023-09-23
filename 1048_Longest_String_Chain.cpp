#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> adj;
    vector<int> longestPath;

    int longestStrChain(vector<string>& words) 
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<string, int> wordToIdx;        
        for(int i = 0; i < words.size(); ++i)
        {
            wordToIdx[words[i]] = i;
        }
        
        this->adj = vector<vector<int>>(words.size(), vector<int>());
        
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].length(); ++j)
            {
                string newWord = words[i].substr(0, j) + words[i].substr(j+1);
                if(wordToIdx.count(newWord) != 0)
                {
                    this->adj[i].push_back(wordToIdx[newWord]);
                }
            }
        }

        this->longestPath = vector<int>(words.size(), 0);
        int ret = 1;
        for(int i = 0; i < words.size(); ++i)
        {          
            DFS(i);
            ret = max(ret, this->longestPath[i]);
        }
        return ret;
    }

    int DFS(const int& i)
    {
        if(this->longestPath[i] == 0)
        {
            this->longestPath[i] = 1;
            for(int& successor: this->adj[i])
            {
                this->longestPath[i] = max(this->longestPath[i], DFS(successor));
            }
        }        
        return this->longestPath[i]+1;
    }  
};


class Solution2 
{
public:
    vector<vector<int>> adj;
    vector<int> longestPath;

    int longestStrChain(vector<string>& words) 
    {
        this->adj = vector<vector<int>>(words.size(), vector<int>());
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words.size(); ++j)
            {
                if(isRelated(words[i], words[j]))
                {
                    adj[i].push_back(j);
                }
            }
        }
        this->longestPath = vector<int>(words.size(), 0);
        int ret = 1;
        for(int i = 0; i < words.size(); ++i)
        {          
            DFS(i);
            ret = max(ret, this->longestPath[i]);
        }
        return ret;
    }

    bool isRelated(const string& predecessor, const string& successor)
    {
        if(successor.length() != predecessor.length()+1)
        {
            return false;
        }
        int i = 0;
        int j = 0;
        bool oneChance = true;
        while(j < successor.length())
        {
            if(predecessor[i] != successor[j])
            {
                if(!oneChance)
                {
                    return false;
                }
                ++j;
                oneChance = false;
            }
            else
            {
                ++i;
                ++j;
            }
        }
        return true;
    }

    int DFS(int i)
    {
        if(this->longestPath[i] == 0)
        {
            this->longestPath[i] = 1;
            for(int& successor: this->adj[i])
            {
                this->longestPath[i] = max(this->longestPath[i], DFS(successor));
            }
        }        
        return this->longestPath[i]+1;
    }  
};

int main(int argc, char const *argv[])
{
    string a = "ab";
    string b = "abc";
    string c = "ba";


    cout << Solution2().isRelated(a, b) << '\n';
    cout << Solution2().isRelated(c, b) << '\n';


    return 0;
}
