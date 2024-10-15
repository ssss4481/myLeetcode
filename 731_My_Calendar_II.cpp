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

using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> single_booked;
    vector<pair<int, int>> double_booked;


public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        pair<int, int> request{start, end};

        auto overlaped = [](const pair<int, int>& p1, const pair<int, int>& p2){
            return !(p1.second <= p2.first || p1.first >= p2.second);
        };


        for(auto& record: this->double_booked){
            if(overlaped(record, request)){
                return false;
            }
        }

        for(auto& record: this->single_booked){
            if(overlaped(record, request)){
                this->double_booked.emplace_back(max(record.first, request.first), min(record.second, request.second));
            }
        }
        this->single_booked.emplace_back(move(request));
        return true;
    }
};