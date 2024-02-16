#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) 
    {
        std::unordered_map<int, int> hashMap;
        for(auto& n: arr)
        {
            ++hashMap[n];
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
        for(auto& p : hashMap)
        {
            PQ.push(p.second);
        }
        while(!PQ.empty() && k >= PQ.top())
        {
            k -= PQ.top();
            PQ.pop();
        }     
        return static_cast<int>(PQ.size());    
    }
};

int main(int argc, char const *argv[])
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;
    PQ.push(2);
    PQ.push(1);
    std::cout << PQ.top();

    
    return 0;
}
