#include <algorithm>
#include <vector>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

#define ARRIVE_TIME 0
#define PROCESS_TIME 1

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total_waiting_time = 0;
        long long current_time = 0;

        for(auto& info: customers){
            long long order_completed_time = max(current_time, static_cast<long long>(info[ARRIVE_TIME])) + info[PROCESS_TIME];
            total_waiting_time +=  order_completed_time - info[ARRIVE_TIME];
            current_time = order_completed_time;
        }

        return static_cast<double>(total_waiting_time) / customers.size();
    }
};