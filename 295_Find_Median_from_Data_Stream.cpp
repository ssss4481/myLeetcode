#include <set>
#include <queue>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class MedianFinder {
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