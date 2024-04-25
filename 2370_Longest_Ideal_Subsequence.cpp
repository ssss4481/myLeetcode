#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int longestIdealString(std::string s, int k) {
        const int n = s.length();
        int dp[26] = {0};
        for(int i = 0; i < n; ++i){
            int cur = s[i] - 'a';
            int longest_prev = 0;
            for(int d = -k; d <= k; ++d){
                if(cur + d >= 0 && cur + d < 26){
                    longest_prev = std::max(longest_prev, dp[cur+d]);
                }
            }
            dp[cur] = std::max(dp[cur], longest_prev+1);            
        }
        int ret = 1;
        for(int i = 0; i < 26; ++i){
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};

class Solution1 {//not fast enough
public:
    int longestIdealString(std::string s, int k) {
        int latest_index[26];
        for(int i = 0; i < 26; ++i){
            latest_index[i] = -1;
        }
        latest_index[s[0]-'a'] = 0;
        int n = s.length();
        std::vector<int> dp(n, 1);
        int ret = 1;
        for(int i = 1; i < n; ++i){
            int c = static_cast<int>(s[i]);
            for(int j = -k; j <= k; ++j){
                if(c+j >= 'a' && c+j <= 'z' && latest_index[c+j-'a'] != -1){
                    dp[i] = std::max(dp[i], dp[latest_index[c+j-'a']]+1);
                }
            }
            latest_index[c-'a'] = i;
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};


class Solution2 {//too slow
public:
    int longestIdealString(std::string s, int k) {
        std::unordered_map<int, int> latest_index;
        latest_index[static_cast<int>(s[0])] = 0;
        int n = s.length();
        std::vector<int> dp(n, 1);
        int ret = 1;
        for(int i = 1; i < n; ++i){
            int c = static_cast<int>(s[i]);
            for(int j = -k; j <= k; ++j){
                if(latest_index.count(c+j) != 0){
                    dp[i] = std::max(dp[i], dp[latest_index[c+j]]+1);
                }
            }
            latest_index[c] = i;
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};




class Solution3 {//TLE
public:
    int longestIdealString(std::string s, int k) {
        int n = s.length();
        std::vector<int> dp(n, 1);
        int ret = 1;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(abs(int(s[i])-int(s[j])) <= k){
                    dp[i] = std::max(dp[i], dp[j]+1);
                }
            }
            ret = std::max(ret, dp[i]);
        }
        return ret;
    }
};