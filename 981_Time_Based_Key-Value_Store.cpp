#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef struct valueAndTimestamp
{
public:
    std::vector<std::string> values;
    std::vector<int> timestamps;
}VAT;


class TimeMap 
{
private:
    std::unordered_map<std::string, VAT> hashMap;

public:
    TimeMap() 
    {
        
    }
    
    void set(std::string key, std::string value, int timestamp) 
    {
        if(this->hashMap.count(key) == 0)
        {
            this->hashMap[key] = VAT();
        }
        this->hashMap[key].values.push_back(value);
        this->hashMap[key].timestamps.push_back(timestamp);
    }
    
    std::string get(std::string key, int timestamp) 
    {
        if(this->hashMap.count(key) != 0)
        {
            auto& ref = this->hashMap[key].timestamps;
            int pos = std::upper_bound(ref.begin(), ref.end(), timestamp)-ref.begin();
            if(pos >= 1)
            {
                return this->hashMap[key].values[pos-1];
            }
        }
        return "";
    }
};