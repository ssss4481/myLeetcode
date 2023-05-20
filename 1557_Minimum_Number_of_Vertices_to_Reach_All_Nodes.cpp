#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution2 //practice Kasaraju
{
private:
    vector<int> finished;
    vector<uint8_t> visit;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> reversedAdjMatrix;
    vector<unordered_set<int>>  SCCs;
    vector<int> group;

public:
    void Kasaraju(int n)
    {
        this->visit = vector<uint8_t>(n, 0);

        for(int i = 0; i < n; ++i)                    
            this->forwardDFS(i);
        
        this->visit = vector<uint8_t>(n, 0);
        int k = 0;
        for(int i = n-1; i >= 0; --i)
        {   
            unordered_set<int> SCC;
            if(this->visit[this->finished[i]] == 0)
            {
                this->reverseDFS(this->finished[i], SCC, k);
                ++k;
            }
            if(SCC.size() > 0)
                this->SCCs.push_back(std::move(SCC));
        }

    }

    void forwardDFS(int vertex)
    {
        if(this->visit[vertex])
            return;

        this->visit[vertex] = 1;        
        for(int i = 0; i < this->adjMatrix[vertex].size(); ++i)
        {                     
            forwardDFS(adjMatrix[vertex][i]);            
        }
        this->finished.push_back(vertex);
    }

    void reverseDFS(int vertex, unordered_set<int>& SCC, const int& k)
    {
        if(this->visit[vertex] == 1)
            return;
        this->group[vertex] = k;
        this->visit[vertex] = 1;
        SCC.insert(vertex);
        for(int i = 0; i < this->reversedAdjMatrix[vertex].size(); ++i)
        {            
            reverseDFS(reversedAdjMatrix[vertex][i], SCC, k);            
        }          
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        this->visit = vector<uint8_t> (n, 0);
        this->adjMatrix = vector<vector<int>> (n, vector<int>(0));
        this->reversedAdjMatrix = vector<vector<int>> (n, vector<int>(0));
        this->group = vector<int> (n);

        for(vector<int>& edge :  edges)
        {
            this->adjMatrix[edge[0]].push_back(edge[1]);
            this->reversedAdjMatrix[edge[1]].push_back(edge[0]);
        }
        this->Kasaraju(n);       


        int m = this->SCCs.size();

        vector<int> inDegreeSCCs(m, 0);
        
        for(vector<int>& edge :  edges)
        {            
            ++inDegreeSCCs[group[edge[1]]];               
        }


        vector<int> ret;
        for(int i = 0; i < m; ++i)
        {
            if(inDegreeSCCs[i] == 0)
                ret.push_back(*(this->SCCs[i].begin()));
        }
        return ret;        
    }
};


class Solution
{    
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> indegree (n, 0);
        vector<int> ret;
        for(vector<int>& edge: edges)        
        {            
            ++indegree[edge[1]];
        }
        for(int i = 0; i < n; ++i)
        {
            if(indegree[i] == 0)
                ret.push_back(i);
        }
        return ret;    
    }
};



int main(int argc, char const *argv[])
{
    Solution sol = Solution();
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    vector<int> ret = sol.findSmallestSetOfVertices(n, edges);
    for(int& i : ret)
    {
        cout << i << "\n";
    }

    

    return 0;
}
