#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;




typedef pair<int, unordered_set<int>> pi;
class Solution 
{
public:
    void printInfo(vector<pi>&  piArr)
    {
        for(auto& node: piArr)
        {
            cout <<  node.first << '\t' << node.second.size() << '\n';
        }
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {        
        int ret = 0;
        vector<pi>  piArr(n);
        for(int i = 0; i < n; ++i)
        {
            piArr[i] = make_pair(i, unordered_set<int>());
        }

        for(auto& edge: roads)
        {
            piArr[edge[0]].second.insert(edge[1]);
            piArr[edge[1]].second.insert(edge[0]);
        }
        auto cmp = [](pi a, pi b){ return a.second.size() > b.second.size();};
        sort(piArr.begin(), piArr.end(), cmp);
        //printInfo(piArr);
        const int boundary = n-1;
        for(int i = 0; i < boundary; ++i)
        {
            int ceiling = piArr[i+1].second.size();
            if(piArr[i].second.size() + ceiling < ret)
            {
                break;
            }

            for(int j = i+1; j < n; ++j)
            {
                if(piArr[j].second.size() < ceiling)
                {
                    break;
                }
                int rank = piArr[i].second.size() + piArr[j].second.size();          
                if(piArr[i].second.count(piArr[j].first) == 1)
                {
                    --rank;
                }
                ret = max(ret, rank);
            }
        }
        return ret;
    }
};