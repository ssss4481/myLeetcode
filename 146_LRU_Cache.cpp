#include <unordered_map>
#include <queue>
#include <algorithm>


class LRUCache 
{
private:
    std::unordered_map<int, int> cache;
    std::unordered_map<int, int> mostResentlyUsedTime;
    std::queue< std::pair<int, int> > Q;
    int capacity;
    int tic;

public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;        
        this->tic = 0;
    }
    
    int get(int key) 
    {
        if(this->cache.count(key) == 0)
        {
            return -1;
        }
        else
        {
            this->mostResentlyUsedTime[key] = this->tic;
            this->Q.push(std::make_pair(key, this->tic));
            ++this->tic;
            return this->cache[key];
        }        
    }

    void LRU(int key)
    {
        this->mostResentlyUsedTime[key] = this->tic;
        this->Q.push(std::make_pair(key, this->tic));
        ++this->tic;

        if(this->cache.size() <= capacity)
        {
            return;
        }
        else
        {
            while(1)
            {
                std::pair<int, int>& head = this->Q.front();
                if(this->mostResentlyUsedTime.count(head.first) != 0 && head.second == this->mostResentlyUsedTime[head.first])
                {
                    this->cache.erase(head.first);
                    this->mostResentlyUsedTime.erase(head.first);
                    break;
                }
                this->Q.pop();
            }
        }
    }
    
    void put(int key, int value) 
    {       
        this->cache[key] = value;
        LRU(key);        
    }
};
