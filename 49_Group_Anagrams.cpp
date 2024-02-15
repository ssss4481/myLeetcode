#include <unordered_map>
#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <algorithm>
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
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) 
    {   
        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        for(auto& s: strs)
        {
            std::string copyS = s;
            std::sort(copyS.begin(), copyS.end());
            hashMap[copyS].push_back(s);
        }

        std::vector<std::vector<std::string>> ret;

        for(auto& p: hashMap)
        {
            ret.push_back(p.second);
        }

        return ret;      
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
