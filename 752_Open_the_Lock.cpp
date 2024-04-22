#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
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
    int openLock(std::vector<std::string>& deadends, std::string target) {
        if(target == "0000"){
            return 0;
        }
        std::unordered_set<std::string> deadend_set(deadends.begin(), deadends.end());
        std::unordered_set<std::string> visit;
        int step = 0;
        std::queue<std::string> Q;

        Q.push(target);
        visit.insert(target);

        while (!Q.empty())
        {
            std::queue<std::string> Qsub;
            ++step;
            while (!Q.empty()){
                auto s = Q.front();
                for(int i = 0; i < 4; ++i){
                    ++s[i];
                    if(s[i] > '9'){
                        s[i] = '0';
                    }
                    if(visit.count(s) == 0 && deadend_set.count(s) == 0){
                        Qsub.push(s);
                        visit.insert(s);
                        if(s == "0000"){
                            return step;
                        }
                    }
                    --s[i];
                    if(s[i] < '0'){
                        s[i] = '9';
                    }
                    --s[i];
                    if(s[i] < '0'){
                        s[i] = '9';
                    }     
                    if(visit.count(s) == 0 && deadend_set.count(s) == 0){
                        Qsub.push(s);
                        visit.insert(s);
                        if(s == "0000"){
                            return step;
                        }                        
                    }  
                    ++s[i];
                    if(s[i] > '9'){
                        s[i] = '0';
                    }                                         
                }
                Q.pop();
            }
            Q.swap(Qsub);
        }
        return -1;
    }

};