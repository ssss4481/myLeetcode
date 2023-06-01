#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
    vector<int> prefix(const string& p)
    {
        int m = p.length();
        vector<int> ret(m, 0);
        ret[0] = 0;
        int k = 0;
        for(int i = 1; i < m; ++i)
        {
            while(k > 0 && p[k+1] != p[i])
                k = ret[k-1];
            if(p[k] == p[i])
                ++k;
            ret[i] = k;
        }
        return ret;
    }

    void KMP(string& t, string& p, vector<int>& ans)
    {
        int n = t.length();
        int m = p.length();
        vector<int> pi = this->prefix(p);
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
                ans.push_back(i - m + 1);
                k = pi[k-1];
            }
        }
    }


    void stringSwap(string& p, int a, int b)
    {
        char c = p[a];
        p[a] = p[b];
        p[b] = c;
    }

    void stringPermutation(string& p, string&t, int depth, set<string>& strSet, vector<int>& ans)
    {
        if(depth == p.length()-1)
        {
            //cout << p << "\n";
            if(strSet.count(p) == 0)
            {
                strSet.insert(p);
                this->KMP(t, p, ans);
            }
            return;
        }
        for(int i = depth; i < p.length(); ++i)
        {
            this->stringSwap(p, depth, i);
            this->stringPermutation(p, t, depth+1, strSet, ans);
            this->stringSwap(p, depth, i);
        }
    }

    vector<int> findAnagrams(string t, string p)
    {
        set<string> strSet;
        vector<int> ret;
        this->stringPermutation(p, t, 0, strSet, ret);
        return ret;
    }
};


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
    for(int& k: pi)
    {
        cout << k << " ";
    }
    cout << "\n";
    int k = 0;
    for(int i = 0; i <= n; ++i)
    {
        while(k > 0 && p[k] != t[i])
            k = pi[k-1];
        if(p[k] == t[i])
            ++k;
        if(k == m)
        {
            cout << "valid shift: " << i - m + 1<< "\n";
            k = pi[k-1];
        }
    }
}



int main(int argc, char const *argv[])
{
    string p = "ababbaaa";
    string t = "aababbababbbababbaaabb";
    //Solution sol = Solution();
    KMP(t, p);
    

    return 0;
}
