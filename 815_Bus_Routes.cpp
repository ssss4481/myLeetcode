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


class BusNode{   
public:
    std::unordered_set<int> stops;
    BusNode(){}
    BusNode(const std::vector<int> route){
        this->stops.insert(route.begin(), route.end());
    }

};

class Edges{
public:
    std::unordered_set<int> next;
};

class Solution {
public:
    int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }

        const int n = routes.size();
        std::vector<BusNode> nodes(routes.size());

        for(int i = 0; i < n; ++i){
            nodes[i] = BusNode(routes[i]);
        }

        auto hasCommonElement = [](const std::unordered_set<int>& a, const std::unordered_set<int>& b)
        {
            auto hasCommon = [](const std::unordered_set<int>& smallSet, const std::unordered_set<int>& largeSet)
            {
                for(auto& element: smallSet){
                    if(largeSet.count(element) == 1){
                        return true;
                    }
                }
                return false;
            };

            if(a.size() <= b.size()){
                return hasCommon(a, b);
            }
            return hasCommon(b, a);
        };

        std::vector<Edges> adj(n);

        for(int i = 0; i < n; ++i){
            auto& busI = nodes[i];
            for(int j = i+1; j < n; ++j){
                auto& busJ = nodes[j];
                if(hasCommonElement(busI.stops, busJ.stops)){
                    adj[i].next.insert(j);
                    adj[j].next.insert(i);
                }
            }
        }

        bool visited[n];
        std::memset(visited, 0, n*sizeof(bool));
        
        std::queue<int> Q1;
        for(int i = 0; i < n; ++i){
            if(nodes[i].stops.count(source) == 1){
                Q1.push(i);
                visited[i] = true;
            }
        }

        int depth = 0;
        while(!Q1.empty()){
            ++depth;
            std::queue<int> Q2;
            while(!Q1.empty()){
                int current = Q1.front();
                Q1.pop();
                if(nodes[current].stops.count(target) == 1){
                    return depth;
                }                
                for(auto& nextNode: adj[current].next){
                    if(visited[nextNode] == false){
                        visited[nextNode] = true;
                        Q2.push(nextNode);
                    }
                }
            }
            Q1.swap(Q2);
        }
        return -1;
    }
};




struct Node
{
    std::vector<int> nextNode;
};

class SolutionOld
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
