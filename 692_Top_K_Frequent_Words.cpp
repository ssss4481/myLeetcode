#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef struct Node{
    int index;
    int freq;
    Node(){}
    Node(int _index, int _freq){
        index = _index;
        freq = _freq;
    }
}Node;

class Solution {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
        std::unordered_map<std::string, int> WordToIndex;
        std::unordered_map<std::string, int> WordFreq;
        
        for(int i = 0; i < words.size(); ++i){
            auto& word = words[i];
            ++WordFreq[word];
            if(WordToIndex.count(word) == 0){
                WordToIndex[word] = i;
            }
        }

        auto PQcmp = [&](const Node& a , const Node& b){
            if(a.freq == b.freq){
                return words[a.index] < words[b.index];
            }
            return a.freq > b.freq;
        };

        std::priority_queue<Node, std::vector<Node>, decltype(PQcmp)> PQ(PQcmp);

        for(auto& p : WordFreq){
            auto& word = p.first;
            auto& freq = p.second;
            auto node = Node(WordToIndex[word], freq);
            PQ.push(node);
            if(PQ.size() > k){
                PQ.pop();
            }
        }

        std::vector<std::string> ret(k);
        for(int i = k-1; i >= 0; --i){
            ret[i] = words[PQ.top().index];
            PQ.pop();
        }
        return ret;        
    }
};