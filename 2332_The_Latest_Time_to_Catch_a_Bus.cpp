#include <vector>
#include <algorithm>
#include <set>
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
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        auto cmp = [](int a, int b){return a > b;};

        auto pop = [&cmp](vector<int>& heap)mutable{
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        };
        make_heap(buses.begin(), buses.end(), cmp);
        make_heap(passengers.begin(), passengers.end(), cmp);
        int gap = 1;
        int bus_time;
        int bus_capacity;
        int last_passenger = 1;
        while(!buses.empty() && !passengers.empty()){
            bus_time = buses.front();
            bus_capacity = capacity;
            while(!passengers.empty() && bus_capacity > 0 && passengers.front() <= bus_time){
                --bus_capacity;
                if(passengers.front() - last_passenger > 1){
                    gap = passengers.front()-1;
                }
                last_passenger = passengers.front();
                pop(passengers);
            }
            pop(buses);
        }

        if(!buses.empty()){
            while(buses.size() > 1){
                pop(buses);
            }
            return buses.front();
        }

        if(bus_capacity > 0 && last_passenger < bus_time){
            return bus_time;
        }else{
            return gap;
        }
    }
};

class Solution1 {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {

        auto cmp = [](int a, int b){return a > b;};

        auto pop = [&cmp](vector<int>& heap)mutable{
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        };

        set<int> BST(passengers.begin(), passengers.end());
        BST.insert(0);
        make_heap(buses.begin(), buses.end(), cmp);
        make_heap(passengers.begin(), passengers.end(), cmp);
        int last_passenger;
        int bus_time;
        int bus_capacity;
        while(!buses.empty() && !passengers.empty()){
            bus_time = buses.front();
            bus_capacity = capacity;
            while(!passengers.empty() && bus_capacity > 0 && passengers.front() <= bus_time){
                --bus_capacity;
                last_passenger = passengers.front();
                pop(passengers);
            }
            pop(buses);
        }

        if(!buses.empty()){
            while(buses.size() > 1){
                pop(buses);
            }
            return buses.front();
        }

        if(bus_capacity > 0 && last_passenger < bus_time){
            return bus_time;
        }else{
            auto it = BST.find(last_passenger);
            --it;
            while(last_passenger - (*it) <= 1){
                last_passenger = *it;
                --it;
            }
            return last_passenger-1;
        }
        return 1;
    }
};