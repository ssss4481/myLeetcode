#include <vector>
#include <queue>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class SeatManager 
{
public:
    int nextSeat;    
    std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;

    SeatManager(int n) 
    {
        this->nextSeat = 1;
    }
    
    int reserve() 
    {
        if(this->PQ.empty())
        {
            return this->nextSeat++;
        }
        int seat = PQ.top();
        PQ.pop();
        return seat;        
    }
    
    void unreserve(int seatNumber) 
    {
        PQ.push(seatNumber);        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */