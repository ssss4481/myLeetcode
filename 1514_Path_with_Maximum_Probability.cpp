#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, double> pi;


class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<vector<pi>> adj(n);
        for(int i = 0; i < edges.size(); ++i)
        {  
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
        }




        
        return 0;
    }


    void dijk()
    {

    }

    void relax()
    {
        
    }
};