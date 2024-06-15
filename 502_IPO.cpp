#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <numeric>
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
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        auto sort_cmp = [&](int i, int j ){
            return capital[i] < capital[j];
        };

        vector<int> indices(profits.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), sort_cmp);

        auto PQcmp = [&](int i, int j){
            return profits[i] < profits[j];
        };
        priority_queue<int, vector<int>, decltype(PQcmp)> PQ(PQcmp);
        int t = 0;

        auto push_new_candidates = [&](){
            for(; t < indices.size() && capital[indices[t]] <= w; ++t){
                PQ.push(indices[t]);
            }
        };

        push_new_candidates();
        for(int i = 0; i < k && !PQ.empty(); ++i){
            w += profits[PQ.top()];
            PQ.pop();
            push_new_candidates();
        }
        return w;
    }
};

class Solution1 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        auto cmp = [&](int i, int j){
            return profits[i] < profits[j];
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> PQ(cmp);
        unordered_set<int> waiting_candidates_index;

        for(int i = 0; i < capital.size(); ++i){
            if(capital[i] <= w){
                PQ.push(i);
            }else{
                waiting_candidates_index.insert(i);
            }
        }

        for(int i = 0; i < k && !PQ.empty(); ++i){
            w += profits[PQ.top()];
            PQ.pop();
            vector<int> new_candidates;
            for(auto& c: waiting_candidates_index){
                if(capital[c] <= w){
                    new_candidates.push_back(c);
                    PQ.push(c);
                }
            }
            for(auto& c : new_candidates){
                waiting_candidates_index.erase(c);
            }
        }
        return w;
    }
};