#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
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
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> word_dict(wordList.begin(), wordList.end());

        if(word_dict.count(endWord) == 0){
            return 0;
        }

        std::unordered_set<std::string> visit;
        std::queue<std::string> Q1;
        Q1.push(beginWord);
        visit.insert(beginWord);
        int len = 0;
        while(!Q1.empty()){
            ++len;
            std::queue<std::string> Q2;
            while(!Q1.empty()){
                std::string cur = Q1.front();
                Q1.pop();
                for(int i = 0; i < cur.length(); ++i){
                    char origin_c = cur[i];
                    for(char c = 'a'; c <= 'z'; ++c){
                        cur[i] = c;                        
                        if(word_dict.count(cur) == 1 && visit.count(cur) == 0){
                            if(cur == endWord){
                                return len+1;
                            }
                            Q2.push(cur);
                            visit.insert(cur);
                        }
                    }
                    cur[i] = origin_c;
                }
            }
            Q1.swap(Q2);
        }
        return 0;
    }
};




class Solution1 {//too slow
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        const int n = wordList.size();

        std::vector<std::vector<int>> adj(n);
        
        auto is_connect = [](const std::string& s1, const std::string& s2){
            int distance = 0;
            for(int i = 0; i < s1.length(); ++i){
                if(s1[i] != s2[i]){
                    ++distance;
                }
                if(distance > 1){
                    return false;
                }
            }
            return true;
        };

        int goal = -1;
        bool visit[n];
        memset(visit, false, n*sizeof(bool));        
        std::queue<int> Q1;
        for(int i = 0; i < n; ++i){
            if(wordList[i] == endWord){
                goal = i;
            }
            if(is_connect(beginWord, wordList[i])){
                Q1.push(i);
                visit[i] = true;
            }
            for(int j = i+1; j < n; ++j){
                if(is_connect(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if(goal == -1){
            return 0;
        }

        int len = 1;
        while(!Q1.empty()){
            ++len;
            std::queue<int> Q2;
            while(!Q1.empty()){
                int w = Q1.front();
                if(w == goal){
                    return len;
                }
                for(auto& next: adj[w]){
                    if(!visit[next]){
                        visit[next] = true;
                        Q2.push(next);
                    }
                }
                Q1.pop();
            }
            Q1.swap(Q2);
        }

        return 0;
        
    }
}; 