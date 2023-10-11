#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <map>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people) 
    {             
        auto flower_cmp = [](std::vector<int>& a, std::vector<int>& b)
        {
            return a[0] < b[0];
        };        
        std::sort(flowers.begin(), flowers.end(), flower_cmp);

        std::vector<int> copyPeople = people;
        std::sort(copyPeople.begin(), copyPeople.end());

        auto PQcmp = [&](int& a, int& b)
        {
            return a > b;
        };        

        int flower_idx = 0;
        std::priority_queue<int, std::vector<int>, decltype(PQcmp)> PQ(PQcmp);
        std::unordered_map<int, int> hashMap;

        for(auto& person: copyPeople)
        {
            if(hashMap.count(person) == 0)
            {                
                while(flower_idx < flowers.size() && flowers[flower_idx][0] <= person)
                {
                    PQ.push(flowers[flower_idx++][1]);                                        
                }
                while(!PQ.empty()&& PQ.top() < person)
                {
                    PQ.pop();
                }
                hashMap[person] += PQ.size();
            }
        }

        std::vector<int> ret(people.size());

        for(int i = 0; i < people.size(); ++i)
        {               
            ret[i] = hashMap[people[i]];                       
        }

        return ret;        
    }
};

int main(int argc, char const *argv[])
{
    auto PQcmp = [&](int& a, int& b)
    {
        return a > b;
    };        
    std::priority_queue<int, std::vector<int>, decltype(PQcmp)> PQ(PQcmp);
    PQ.push(3);
    PQ.push(2);
    std::cout<<PQ.top() << '\n';


    return 0;
}
