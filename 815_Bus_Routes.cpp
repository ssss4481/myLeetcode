#include <vector>
#include <unordered_set>
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

struct Node
{
    std::vector<int> nextNode;
};

class Solution 
{
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) 
    {
        if(source == target)
        {
            return 0;
        }
        
        const int n = routes.size();


        std::vector<Node> adj(n);
        
        std::queue<int> startQueue;     
        std::unordered_set<int> targetSet;
        //build node
        //build nextNode
        auto hasCommonStop = [&](std::unordered_set<int>& routeSet, int r2)
        {
            for(auto& stop2: routes[r2])
            {
                if(routeSet.count(stop2) == 1)
                {
                    return true;
                }
            }
            return false;
        };

        auto isStart = [&](std::unordered_set<int>& routeSet){ return routeSet.count(source) == 1;};
        auto isTarget = [&](std::unordered_set<int>& routeSet){ return routeSet.count(target) == 1;};
        
        for(int i = 0; i < n; ++i)
        {
            std::unordered_set<int> routeSet(routes[i].begin(), routes[i].end());
            for(int j = i+1; j < n; ++j)
            {
                if(hasCommonStop(routeSet, j))
                {
                    adj[i].nextNode.push_back(j);
                    adj[j].nextNode.push_back(i);
                }
            }
            if(isStart(routeSet))
            {
                startQueue.push(i);
            }
            if(isTarget(routeSet))
            {
                targetSet.insert(i);
            }
        }

        //BFS
        int distance = 0;
        std::queue<int> nextQueue;
        std::vector<bool> visited(n, false);
        while(!startQueue.empty())
        {
            ++distance;
            while(!startQueue.empty())
            {
                if(visited[startQueue.front()])
                {
                    startQueue.pop();
                    continue;
                }

                if(targetSet.count(startQueue.front()) == 1)
                {
                    return distance;
                }
                visited[startQueue.front()] = true;

                for(auto& next: adj[startQueue.front()].nextNode)
                {
                    if(!visited[next])
                    {
                        nextQueue.push(next);
                    }
                }
            }
            startQueue.swap(nextQueue);
        }
        return -1;
    }
};
