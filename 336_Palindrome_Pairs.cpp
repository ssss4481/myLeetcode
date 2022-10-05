#include <vector>
#include <string>
#include <map>

using namespace std;
class TrieNode
{
    public:
        TrieNode()
        {
            this->idx = -1;
        }
        TrieNode(int idx, char c)
        {
            this->idx = idx;

        }
    private:
        int idx;
        char c;
        map<char, TrieNode*> links;


}


class Trie
{
    public:
        Trie()
        {
            root = new TrieNode();
        }
    private:
            Trie* root;
};


class Solution
{
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        vector<vector<int>> ret;
        return ret;
    }


};






class Solution1 {
    public:
        bool palindromeChecker(const string& a, const string& b)
        {
            string temp = a + b;
            int lo = 0;
            int hi = temp.size()-1;
            while(lo < hi)
            {
                if(temp[lo] != temp[hi])
                    return false;

                ++lo;
                --hi;
            }
            return true;
        }



        vector<vector<int>> palindromePairs(vector<string>& words)
        {
            vector<vector<int>> ret;
            for(int i = 0; i < words.size(); ++i)
            {
                for(int j = i+1; j < words.size(); ++j)
                {
                    if(palindromeChecker(words[i], words[j]))
                        ret.push_back({i, j});
                    if(palindromeChecker(words[j], words[i]))
                        ret.push_back({j, i});
                }
            }
            return ret;
        }
};

int main()
{
    return 0;
}