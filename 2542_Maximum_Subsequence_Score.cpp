#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>



using namespace std;

typedef pair<int, int> pi;

class Solution 
{
public:
    static bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
    {
        return (a.second > b.second);
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<pi> nums1AndNums2 (nums1.size());
        for(int i = 0; i < nums1.size(); ++i)
        {
            nums1AndNums2[i] = make_pair(nums1[i], nums2[i]);
        }
        sort(nums1AndNums2.begin(), nums1AndNums2.end(), Solution::sortbysec);

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ret = 0;
        long long kSum = 0;        
        
        for(int i = 0; i < nums1.size(); ++i)
        {
            if(pq.size() < k)
            {
                kSum += nums1AndNums2[i].first;
                pq.push(nums1AndNums2[i].first);
                if(pq.size() == k)
                {
                    long long roundSum = kSum * nums1AndNums2[i].second;
                    if(roundSum > ret)
                    {
                        ret = roundSum;
                    }
                }
            }
            else
            {
                if(nums1AndNums2[i].first > pq.top())
                {
                    kSum -= pq.top();
                    kSum += nums1AndNums2[i].first;
                    pq.pop();
                    pq.push(nums1AndNums2[i].first);                  
                }

                long long roundSum = kSum * nums1AndNums2[i].second;
                if(roundSum > ret)
                {
                    ret = roundSum;
                }
            }
        }
        return ret;        
    }
};