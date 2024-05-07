#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

//[enqueueTimei, processingTimei] 
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        auto idx_arr_cmp = [&](int i, int j){
            return tasks[i][0] < tasks[j][0];
        };

        auto idx_priority_cmp = [&](int i, int j){
            if(tasks[i][1] == tasks[j][1]){
                return i > j;
            }
            return tasks[i][1] > tasks[j][1];
        };

        vector<int> indices(tasks.size());
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), idx_arr_cmp);

        priority_queue<int, vector<int>, decltype(idx_priority_cmp)> PQ(idx_priority_cmp);

        vector<int> res;
        res.reserve(tasks.size());
        int i = 0;
        long long t = 0;

        while(res.size() < tasks.size()){
            while(i < indices.size() && tasks[indices[i]][0] <= t){
                PQ.push(indices[i++]);
            }
            if(!PQ.empty()){
                auto task_i = PQ.top();
                PQ.pop();
                t += tasks[task_i][1];
                res.push_back(task_i);
            }else{
                ++t;
            }
        }
        return res;
    }
};