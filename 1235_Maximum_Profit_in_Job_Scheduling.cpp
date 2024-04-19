#include <vector>
#include <map>

typedef struct Job{
    int start;
    int end;
    int profit;
    Job(){}
    Job(int _start, int _end, int _profit){
        start = _start;
        end = _end;
        profit = _profit;
    }
}Job;


class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        
        std::vector<Job> jobs(startTime.size());

        for(int i = 0; i < startTime.size(); ++i){
            auto currentJob = Job(startTime[i], endTime[i], profit[i]);
            jobs[i] = std::move(currentJob);
        }

        auto cmp = [](const Job& a, const Job& b){
            return a.end < b.end;
        };

        std::sort(jobs.begin(), jobs.end(), cmp);

        std::map<int, int> dp{{0, 0}};

        for(int i = 0; i < startTime.size(); ++i){
            auto& job = jobs[i];
            auto it = std::prev(dp.upper_bound(job.start));
            int cur = it->second + job.profit;
            if(cur > dp.rbegin()->second){
                dp[job.end] = cur;
            }
        }

        return dp.rbegin()->second;
    }
};