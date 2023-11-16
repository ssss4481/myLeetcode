#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) 
    {
        std::unordered_map<int, std::vector<int>> adj;        
        for(auto& p: adjacentPairs)
        {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        std::vector<int> ret(adjacentPairs.size()+1);                 
        for(auto& p: adj)
        {
            if(p.second.size() == 1)
            {
                ret[0] = p.first;
                ret[1] = p.second[0];
                break;
            }
        }

        int idx = 2;
        while(idx < ret.size())
        {
            for(auto& next: adj[ret[idx-1]])
            {
                if(next != ret[idx-2])
                {
                    ret[idx++] = next;
                    break;
                }
            }
        }
        return ret;
    }
};





class Solution3 
{
public:
    std::unordered_map<int, std::vector<int>> adj;
    
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) 
    {
        
        for(auto& p: adjacentPairs)
        {
            this->adj[p[0]].push_back(p[1]);
            this->adj[p[1]].push_back(p[0]);
        }
        std::vector<int> ret(adjacentPairs.size()+1);                 
        for(auto& p: this->adj)
        {
            if(p.second.size() == 1)
            {
                ret[0] = p.first;
                int idx = 1;
                this->addToArr(p.second[0], idx, ret);
                break;
            }
        }
        return ret;
    }

    void addToArr(int node, int idx, std::vector<int>& ret)
    {
        ret[idx] = node;
        for(auto& next: this->adj[node])
        {
            if(next != ret[idx-1])
            {
                addToArr(next, ++idx, ret);
                return;
            }
        }                        
    }

};


class Solution2//too slow
{
public:
    std::unordered_map<int, std::vector<int>> adj;
    std::vector<int> ret;
    int idx = 0;
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) 
    {
        
        for(auto& p: adjacentPairs)
        {
            this->adj[p[0]].push_back(p[1]);
            this->adj[p[1]].push_back(p[0]);
        }
        
        std::unordered_set<int> visit;
        this->ret = std::vector<int> (adjacentPairs.size()+1);         
        for(auto& p: this->adj)
        {
            if(p.second.size() == 1)
            {
                DFS(p.first, visit);
            }
        }



        return this->ret;
    }

    void DFS(int node, std::unordered_set<int>& visit)
    {
        if(visit.count(node) == 1)
        {
            return;
        }
        visit.insert(node);
        this->ret[this->idx++] = node;
        for(auto& next : this->adj[node])
        {
            DFS(next, visit);
        }
    }
};