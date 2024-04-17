#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef struct Data{
    int val;
    int freq;
    int time;
    Data(){}
    Data(int _val, int _freq, int _time){   
        val = _val;
        freq = _freq;
        time = _time;
    }
}Data;

struct cmp{
    bool operator() (const Data& lhs, const Data& rhs){
        return lhs.freq == rhs.freq ? lhs.time < rhs.time : lhs.freq < rhs.freq;
    }
};

class FreqStack {
private:
    std::unordered_map<int, int> FreqMap;
    std::priority_queue<Data, std::vector<Data>, cmp> PQ;
    int time;

public:
    FreqStack() {
        this->time = 0;
    }
    
    void push(int val) {
        ++this->FreqMap[val];
        ++this->time;
        auto data = Data(val, this->FreqMap[val], this->time);
        PQ.push(data);
    }
    
    int pop(){
        auto data = PQ.top();
        PQ.pop();
        --this->FreqMap[data.val];
        return data.val;
    }
};
