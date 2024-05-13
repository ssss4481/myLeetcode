#include <iostream>
#include <vector>
#include <algorithm>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<double> arrive_time(n);
        for(int i = 0; i < n; ++i){
            arrive_time[i] = static_cast<double>(target-position[i])/speed[i];

        }

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        auto cmp = [&](int i, int j){
            return position[i] > position[j];
        };

        sort(indices.begin(), indices.end(), cmp);

        int count = 0;
        double threshold = 0;
        for(auto& i: indices){
            if(arrive_time[i] > threshold){
                ++count;
                threshold = arrive_time[i];
            }
        }
        return count;
    }
};

struct Info{
    int pos;
    int speed;
    Info(){}
    Info(int p, int s):pos{p}, speed{s}{}
};

class Solution1 {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        const int n = position.size();
        std::vector<Info> infos(n);
        for(int i = 0; i < n; ++i){
            infos[i] = Info(position[i], speed[i]);
        }

        auto cmp = [](Info& a, Info& b){
            return a.pos < b.pos;
        };

        double cur = 0;
        int res = 0;
        std::make_heap(infos.begin(), infos.end(), cmp);
        while(!infos.empty()){
            auto info = infos.front();
            double time = static_cast<double>(target - info.pos)/info.speed;
            std::pop_heap(infos.begin(), infos.end(), cmp);
            infos.pop_back();
            if(time <= cur){
                continue;
            }
            cur = time;
            ++res;
        }
        return res;
    }
};