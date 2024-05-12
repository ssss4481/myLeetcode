#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int res = 0;
        unordered_map<char, int> idx;
        for(int i = 0; i < t.size(); ++i){
            idx[t[i]] = i;
        }

        for(int i = 0; i < s.size(); ++i){
            res += abs(i-idx[s[i]]);
        }

        return res;
    }
};