#include <vector>
#include <unordered_set>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        auto& e1 = edges.front();
        auto& e2 = edges.back();
        if(e1.front() == e2.front()){
            return e1.front();
        }
        if(e1.front() == e2.back()){
            return e1.front();
        }
        return e1.back();
    }
};


class Solution1 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> nodes;
        for(auto& edge: edges){
            for(auto& node: edge){
                if(nodes.count(node) != 0){
                    return node;
                }
                nodes.insert(node);
            }
        }
        return -1;
    }
};