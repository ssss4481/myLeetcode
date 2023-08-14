#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;


class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 1; i < k; ++i)
        {
            pq.pop();
        }      
        return pq.top();
    }
};

class Solution2
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for(int& num: nums)
        {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }
        vector<int> countVec(maxValue-minValue+1, 0);
        for(int& num: nums)
        {
            ++countVec[num-minValue];
        }
        auto pNum = countVec.end()-1;
        for(; k > 0;  --pNum)
        {
            k -= (*pNum);             
        }
        return (pNum-countVec.begin()+1)+minValue;
    }

};


int main(int argc, char const *argv[])
{
    vector<int> a = {1, 2, 3};
    priority_queue<int> b(a.begin(), a.end());
    cout << b.top() << '\n';



    return 0;
}
