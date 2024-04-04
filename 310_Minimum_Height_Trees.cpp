#include <vector>
#include <algorithm>
#include <iostream>

void printVec(std::vector<int>& v)
{
    for(auto& n : v)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
class Solution 
{
public:
    std::vector<std::vector<int>> adj;
    std::vector<bool> visit;
    std::vector<int> maxs;
    int minHeigth;

    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) 
    {
        this->adj = std::vector<std::vector<int>> (n, std::vector<int>());
        this->visit = std::vector<bool> (n, false);
        this->maxs = std::vector<int>(n, 0);
        this->minHeigth = INT_MAX;

        for(auto& edge: edges)
        {
            this->adj[edge[0]].push_back(edge[1]);
            this->adj[edge[1]].push_back(edge[0]);
        }

        return {};
    }


    int DFS(int depth, int node)
    {
        return 0; 
    }

    void updateAgain()
    {

    }
};