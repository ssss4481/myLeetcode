#include <vector>
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
    std::vector<std::vector<int>> adj;
    std::vector<int> inOrder;
    std::vector<char> visit;
    std::vector<int> ret;

    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) 
    {
        this->adj = std::vector<std::vector<int>> (numCourses, std::vector<int>());
        this->inOrder = std::vector<int>(numCourses, 0);
        for(auto& v : prerequisites)
        {
            this->adj[v[1]].push_back(v[0]);
            ++this->inOrder[v[0]];
        }
        this->visit = std::vector<char> (numCourses, 0);
        for(int i = 0; i < numCourses; ++i)
        {
            if(DFS(i) == -1)
            {
                return {};
            }
        }
        std::reverse(this->ret.begin(), this->ret.end());
        return this->ret;
    }

    int DFS(int course)
    {
        if(this->visit[course] == 1)
        {
            return -1;
        }
        
        if(this->visit[course] == 2)
        {   
            return 0;
        }
        this->visit[course] = 1;
        for(auto& next: this->adj[course])
        {
            if(DFS(next) == -1)
            {
                return -1;
            }
        }
        this->ret.push_back(course);
        this->visit[course] = 2;
        return 0;
    }
};