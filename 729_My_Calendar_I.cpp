#include <iostream>
#include <algorithm>
#include <set>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

struct cmp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
        return a.first < b.first;
    }
};

class MyCalendar {
private:
    set<pair<int, int>, cmp> booked;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        const pair<int, int> query = {start, end};
        auto next = this->booked.lower_bound(query);

        if(next != this->booked.end() && (*next).first < end){
            return false;
        }
        if(next != this->booked.begin()){
            auto previous = prev(next);
            if((*previous).second > start){
                return false;
            }
        }
        
        this->booked.insert(query);
        return true;
    }
};