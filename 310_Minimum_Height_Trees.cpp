#include <vector>
#include <algorithm>
#include <unordered_set>
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

    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) 
    {
        std::vector<std::unordered_set<int>> adj(n, std::unordered_set<int>());
        int validCount = n;
        if(n == 1)
        {
            return {0};
        }
        if(n == 2)
        {
            return {0, 1};
        }


        for(auto& edge: edges)
        {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        std::unordered_set<int> retSet;
        std::vector<int> removeTargets;


        for(int i = 0; i < n; ++i)
        {
            if(adj[i].size() == 1)
            {
                --validCount;
                removeTargets.push_back(i);
            }
        }    

        if(validCount <= 2)
        {
            for(auto& target: removeTargets)
            {
                retSet.insert(*adj[target].begin());
            }
        }            

        while(validCount > 2)
        {
            std::vector<int> nextRoundRemoveTarget;

            for(auto& target: removeTargets)
            {
                adj[*adj[target].begin()].erase(target);
                if(adj[*adj[target].begin()].size() == 1)
                {
                    nextRoundRemoveTarget.push_back(*adj[target].begin());
                    --validCount;
                }
            } 

            removeTargets.swap(nextRoundRemoveTarget);
            if(validCount <= 2)
            {
                for(auto& target: removeTargets)
                {
                    retSet.insert(*adj[target].begin());
                }
            }
        }

        std::vector<int> retVec;
        retVec.reserve(validCount);
        for (auto it = retSet.begin(); it != retSet.end(); ) 
        {
            retVec.push_back(std::move(retSet.extract(it++).value()));
        }


        return retVec;
    }
};






