#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define pi pair<int, int>

class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ret;
        vector<int> table (20001, 0);
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for(int& num: nums)
        {
            ++table[num+10000];
        }
        
        for(int i = 0; i < 20001; ++i)
        {
            if(pq.size() < k)
            {
                if(table[i] > 0)
                {
                    pq.push(make_pair(table[i], i-10000));
                }
            }
            else if(table[i] > pq.top().first)
            {               
                pq.pop();
                pq.push(make_pair(table[i], i-10000));
            }             
        }

        while(pq.size() > 0)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }

        return ret;
        
    }
};