#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef std::pair<char, int> pi;
class Solution 
{
public:
    std::string frequencySort(std::string s) 
    {
        auto cmp = [](pi& a, pi& b)
        {
            return a.second < b.second;
        };
        std::priority_queue<pi, std::vector<pi>, decltype(cmp)> PQ(cmp);

        std::unordered_map<char, int> hashMap;

        for(auto& c : s)
        {
            ++hashMap[c];
        }

        for(auto& p: hashMap)
        {
            PQ.push(p);
        }

        int i = 0;        
        while(!PQ.empty())
        {
            auto charAndCount = PQ.top();
            PQ.pop();
            while (charAndCount.second > 0)
            {
                --charAndCount.second;
                s[i++] = charAndCount.first;
            }          
        }
        return s;        
    }
};

class Solution1
{
public:
    std::string frequencySort(std::string s) 
    {
        std::unordered_map<char, int> hashMap;
        std::vector<char> chars;

        for(auto& c: s)
        {
            if(hashMap.count(c) == 0)
            {
                chars.push_back(c);
            }
            ++hashMap[c];
        }

        auto cmp = [&hashMap](char& a, char& b)
        {
            return hashMap[a] > hashMap[b];
        };

        std::sort(chars.begin(), chars.end(), cmp);

        int i = 0;
        for(auto& c: chars)
        {
            while(hashMap[c]-- != 0)
            {                
                s[i++] = c;                
            }            
        }
        return s;        
    }
};