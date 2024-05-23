#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtracking(s, result, current, 0);
        return result;
    }

    void backtracking(const string& s, vector<vector<string>>& result, vector<string>& current, int idx){
        if(idx == s.size()){
            result.push_back(current);
            return;
        }

        for(int i = idx; i < s.size(); ++i){
            if(isPalindrome(s, idx, i)){
                current.push_back(s.substr(idx, i-idx+1));
                backtracking(s, result, current, i+1);
                current.pop_back();
            }
        }

    }

    bool isPalindrome(const string& s, int lo, int hi){
        while(lo < hi){
            if(s[lo] != s[hi]){
                return false;
            }
            ++lo;
            --hi;
        }
        return true;
    }
};