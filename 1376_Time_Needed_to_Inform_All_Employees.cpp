#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        //BFS
        queue<int> Q1;
        vector<vector<int>> subordinates(n, vector<int>(0));
        vector<int> time(n, 0);

        for(int i = 0; i < n; ++i)
        {
            if(i != headID)
                subordinates[manager[i]].push_back(i);       
        }        

        Q1.push(headID);       
        while(!Q1.empty())
        {
            int& M = Q1.front();
            for(int i = 0; i < int(subordinates[M].size()); ++i)
            {
                Q1.push(subordinates[M][i]);
                time[subordinates[M][i]] = time[M] + informTime[M];
            }
            Q1.pop();
        }

        return *(max_element(time.begin(), time.end()));
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 6;
    int headID = 2;
    vector<int> manager{2, 2, -1, 2, 2, 2};
    vector<int> informTime{0, 0, 1, 0, 0, 0};

    sol.numOfMinutes(n, headID, manager, informTime);



    return 0;
}
