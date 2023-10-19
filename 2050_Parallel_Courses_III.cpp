#include <vector>
#include <iostream>
#include <algorithm>


const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution//100%
{
public:
    int ret = 0;
    std::vector<std::vector<int>> adj;
    std::vector<int> visitRecord;

    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) 
    {   
        this->adj = std::vector<std::vector<int>>(n+1, std::vector<int>(0));
        for(auto& relation: relations)
        {
            adj[relation[0]].push_back(relation[1]);
        }
        this->visitRecord = std::vector<int> (n+1, 0);
        for(int i = 1; i < n+1; ++i)
        {
            if(visitRecord[i] == 0)
            {
                this->DFS(i, time);
            }
        }

        return this->ret;
    }

    void DFS(int course, std::vector<int>& time)
    {        
        if(this->visitRecord[course] != 0)
        {
            return;
        }
        for(auto& nextCourse: this->adj[course])
        {
            DFS(nextCourse, time);
            this->visitRecord[course] = std::max(this->visitRecord[course], this->visitRecord[nextCourse]);
        }
        this->visitRecord[course] += time[course-1];
        this->ret = std::max(this->ret, this->visitRecord[course]);     
        return;
    }
};




class Solution2//TLE 
{
public:
    int ret = 0;
    std::vector<std::vector<int>> adj;
    //std::vector<char> visit;
    std::vector<char> hasInDegree;

    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) 
    {   
        this->adj = std::vector<std::vector<int>>(n+1, std::vector<int>(0));
        this->hasInDegree = std::vector<char> (n+1, 0);
        for(auto& relation: relations)
        {
            adj[relation[0]].push_back(relation[1]);
            hasInDegree.at(relation[1]) = 1;
        }

        auto doDFS =[&](int startCourse)
        {
            //this->visit = std::vector<char> (n, 0);
            this->DFS(startCourse, 0, time);
        };

        for(int i = 1; i < n+1; ++i)
        {
            if(hasInDegree[i] == 0)
            {
                doDFS(i);
            }
        }

        return this->ret;
    }

    void DFS(int course, int accuTime, std::vector<int>& time)
    {
        accuTime += time[course-1];
        for(auto& nextCourse: this->adj[course])
        {
            DFS(nextCourse, accuTime, time);
        }
        this->ret = std::max(this->ret, accuTime);     
        return;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    std::vector<std::vector<int>> relations{{1, 3}, {2, 3}};
    std::vector<int> time{3, 2, 5};
    Solution().minimumTime(n ,relations, time);
    return 0;
}




// int main(int argc, char const *argv[])
// {
//     int n = 5;
//     std::vector<std::vector<int>> relations{{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
//     std::vector<int> time{1, 2, 3, 4, 5};
//     Solution().minimumTime(n ,relations, time);
//     return 0;
// }

