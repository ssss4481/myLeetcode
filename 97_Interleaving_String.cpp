#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<char>> table(s1.size()+1, vector<char>(s2.size()+1, 1));
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        return tryInterleave(s1, s2, s3, 0, 0, 0, table);
    }

    bool tryInterleave(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<char>>& table){
        if(k == s3.size()){
            if(i == s1.size() && j == s2.size()){
                return true;
            }
            return false;
        }
        if(table[i][j] == 0){
            return false;
        }
        if(i < s1.size() && s1[i] == s3[k] && tryInterleave(s1, s2, s3, i+1, j, k+1, table)){
            return true;
        }else if(j < s2.size() && s2[j] == s3[k] && tryInterleave(s1, s2, s3, i, j+1, k+1, table)){
            return true;
        }
        table[i][j] = 0;
        return false;
    }
};