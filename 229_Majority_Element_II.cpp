#include <vector>
#include <iostream>
#include <unordered_map>

static const int n = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();    


class Solution1
{
public:
    std::vector<int> majorityElement(std::vector<int>& nums) 
    {
        const int bound = nums.size()/3;

        std::vector<int> ret;

        return ret;
    }
};


class Solution2 
{
public:
    std::vector<int> majorityElement(std::vector<int>& nums) 
    {
        const int bound = nums.size()/3;
        std::unordered_map<int, int> map;
        for(auto& n: nums)
        {
            ++map[n];
        }
        std::vector<int> ret;
        for(auto& p: map)
        {
            if(p.second > bound)
            {
                ret.push_back(p.first);
            }
        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    std::unordered_map<int, int> map;
    map[3]= 2;
    map[4]= 1;
    for(auto& p: map)
    {
        std::cout << p.first << ' ' <<p.second << '\n' ;
    }

    

    return 0;
}
