#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    vector<vector<bool>>& visit;
    unordered_map <char, unordered_map>;

    Solution()
    {
        this->visit = (board.size(), vector<bool>(board[0].size(), false));
    }
    bool DFS(string& target, int i, vector<vector<char>>& board, int x, int y)
    {
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || this->visit[x][y] != 0 || target[i] !=  board[x][y])
            return false;

        if(i == target.size()-1)
            return true;

        this->visit[x][y] = true;
        ++i;

        bool result = DFS(target, i, board, x+1, y, this->visit) || DFS(target, i, board, x-1, y, this->visit) || DFS(target, i, board, x, y+1, this->visit) || DFS(target, i, board, x, y-1, this->visit);

        if(result)
            return result;

        this->visit[x][y] = false;
        return result;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        vector<string> ret;
        for(auto& word: words)
        {
            //cout << word << "\n";
            bool found = false;
            for(auto& vec: visit)
            {
                fill(vec.begin(), vec.end(), false);
            }

            for(int x = 0; x < board.size(); ++x)
            {
                for(int y = 0; y < board[0].size(); ++y)
                {
                    if(DFS(word, 0, board, x, y))
                    {
                        ret.push_back(word);
                        found = true;
                        break;
                    }
                }
                if(found)
                {
                    break;
                }
            }
        }
        return ret;
    }
};


int main()
{
    vector<vector<char>> testCase = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<vector<char>> testCase2 = {{'a', 'b'}};
    vector<string> targets = {"oath"};
    vector<string> targets2 = {"ba"};
    //cout << testCase2.size() <<  testCase2[0].size();
    Solution sol = Solution();
    vector<string> ret = sol.findWords(testCase2, targets2);

    for(auto& res: ret)
    {
        cout << res << "\n";
    }

    return 0;
}