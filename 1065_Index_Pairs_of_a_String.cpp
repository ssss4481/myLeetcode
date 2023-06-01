#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{
private:
    vector<vector<int>> ret;


public:

    vector<int> prefix(const string& p)
    {
        int m = p.length();
        vector<int> ret(m, 0);
        ret[0] = 0;
        int k = 0;
        for(int i = 1; i < m; ++i)
        {
            while(k > 0 && p[k] != p[i])
                k = ret[k-1];
            if(p[k] == p[i])
                ++k;
            ret[i] = k;
        }
        return ret;
    };

    void KMP(string& t, string& p)
    {
        int n = t.length();
        int m = p.length();
        vector<int> pi = prefix(p);
        int k = 0;
        for(int i = 0; i <= n; ++i)
        {
            while(k > 0 && p[k] != t[i])
                k = pi[k-1];
            if(p[k] == t[i])
                ++k;
            if(k == m)
            {
                //cout << "valid shift: " << i - m + 1<< "\n";
                this->ret.push_back({i - m + 1, i});
                k = pi[k-1];
            }
        }
    }


    vector<vector<int>> indexPairs(string text, vector<string>& words) 
    {
        for(auto& word: words)
        {
            this->KMP(text, word);
        }
        sort(this->ret.begin(), this->ret.end());
        return ret;
    }
};