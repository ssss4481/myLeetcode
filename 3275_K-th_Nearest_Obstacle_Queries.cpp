#include <iostream>
#include <queue>

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
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> PQ;
        vector<int> result;
        result.reserve(queries.size());

        for(auto& query: queries){
            int x = query[0];
            int y = query[1];
            int key = abs(x) + abs(y);
            if(PQ.size() < k){
                PQ.push(key);
            }else{
                if(key < PQ.top()){
                    PQ.pop();
                    PQ.push(key);
                }
            }

            if(PQ.size() < k){
                result.emplace_back(-1);
            }else{
                result.emplace_back(PQ.top());
            }
        }
        return result;
    }
};