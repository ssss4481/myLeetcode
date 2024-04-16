#include <unordered_map>
#include <list>


class LRUCache {
private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> KeyToNode;
    std::list<std::pair<int, int>> Cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(this->KeyToNode.count(key) == 1){
            auto node = this->KeyToNode[key];
            this->Cache.splice(this->Cache.begin(), this->Cache, node);
            return node->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(this->KeyToNode.count(key)){
            auto node = this->KeyToNode[key];
            this->Cache.splice(this->Cache.begin(), this->Cache, node);
            node->second = value;
            return;
        }

        if(this->Cache.size() == this->capacity){
            this->KeyToNode.erase(this->Cache.back().first);
            this->Cache.pop_back();
        }
        this->Cache.push_front({key, value});
        this->KeyToNode[key] = this->Cache.begin();
    }
};

