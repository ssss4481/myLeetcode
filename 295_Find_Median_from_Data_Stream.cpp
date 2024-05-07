#include <queue>
#include <iostream>
using namespace std;


class MedianFinder {
private:
    priority_queue<double> PQ_small;
    priority_queue<double, vector<double>, greater<double>> PQ_large;


public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        PQ_large.push(num);
        if(PQ_small.size() < PQ_large.size()){
            PQ_small.push(PQ_large.top());
            PQ_large.pop();
        }

        if(!PQ_large.empty()){
            while(PQ_small.top() > PQ_large.top()){
                PQ_large.push(PQ_small.top());
                PQ_small.push(PQ_large.top());
                PQ_large.pop();
                PQ_small.pop();
            }
        }
    }
    
    double findMedian() {
        if(PQ_small.size() == PQ_large.size()){
            return (PQ_small.top() + PQ_large.top())/2;
        }else{
            return PQ_small.top();
        }
    }
};


class MedianFinder2 {
private:
    std::priority_queue<int> small_heap;
    std::priority_queue<int> large_heap;

public:
    MedianFinder() {
    }

    
    void addNum(int num) {
        small_heap.push(num);
        large_heap.push(-small_heap.top());
        small_heap.pop();
        if(large_heap.size() > small_heap.size()){
            small_heap.push(-large_heap.top());
            large_heap.pop();
        }
    }
    
    double findMedian() {
        if(small_heap.size() == large_heap.size()){
            return (static_cast<double>(small_heap.top())-large_heap.top())/2;
        }
        return small_heap.top();
    }
};




class MedianFinder1 {//too slow
private:
    std::multiset<int> st;

public:
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int mid = st.size()/2;
        auto it = st.begin();
        while(mid-- > 0){
            ++it;
        }
        int ret = *it;
        if(st.size() % 2 == 0){
            --it;
            ret += *it;
            return static_cast<double>(ret)/2;
        }
        return static_cast<double>(ret);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */