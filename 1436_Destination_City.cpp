#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) 
    {
        std::unordered_set<std::string> notDst;
        for(auto& edge: paths)
        {
            notDst.insert(edge[0]);
        }
        for(auto& edge: paths)
        {
            if(notDst.count(edge[1]) == 0)
            {
                return edge[1];
            }
        }        
        return "Should not return here";
    }
};


class Solution1 
{
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) 
    {
        std::unordered_map<std::string, std::string> adj;
        for(auto& edge: paths)
        {
            adj[edge[0]] = edge[1];
        }
        std::string current = paths[0][1];

        while(adj.count(current))
        {
            current = adj[current];
        }
        return current;        
    }
};