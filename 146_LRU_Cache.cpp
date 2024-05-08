#include <unordered_map>
#include <list>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hashmap; //key to node

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hashmap.count(key) == 0){
            return -1;
        }
        auto it = hashmap[key];
        int value = (*it).second;
        cache.erase(it);
        cache.push_back({key, value});
        it = cache.end();
        --it;
        hashmap[key] = it;
        return value;
    }

    void put(int key, int value) {
        if(hashmap.count(key) == 1){
            auto it = hashmap[key];
            cache.erase(it);
            cache.push_back({key, value});
            it = cache.end();
            --it;
            hashmap[key] = it;
            return;
        }

        if(capacity > 0){
            --capacity;
        }else{
            int key = cache.front().first;
            cache.pop_front();
            hashmap.erase(key);
        }
        cache.push_back({key, value});
        auto it = cache.end();
        --it;
        hashmap[key] = it;            
    }
};