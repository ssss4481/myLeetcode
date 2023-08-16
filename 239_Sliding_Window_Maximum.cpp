#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        typedef pair<int, int> pi;
        const int n = nums.size();
        vector<int> ret;
        auto cmp = [](const pi& a, const pi& b)-> bool {return a.first < b.first;};
        priority_queue<pi, vector<pi>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < k-1; ++i)
        {
            pq.push(make_pair(nums[i], i));
        }

        int lo = 0;
        int hi = k-1;

        while (hi < n)
        {
            pq.push(make_pair(nums[hi], hi));
            while(pq.top().second < lo)
            {
                pq.pop();
            }
            ret.push_back(pq.top().first);
            ++lo;
            ++hi;            
        }   
        return ret;                
    }
};




class Solution2
{
public:
    int localMaxIdx;
    int localMax;  

    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {     
        if(k == 1)
        {
            return nums;
        }          

        const int n = nums.size();
        vector<int> ret;
        //init
        this->localMaxIdx = max_element(nums.begin(), nums.begin()+k) - nums.begin();
        this->localMax = nums.at(this->localMaxIdx);
        ret.push_back(this->localMax);
        //cout << "here\n";
        for(int i = k; i < n; ++i)
        {
            if(i - this->localMaxIdx > k-1)
            {
                this->maxInWindow(nums, i, k);
            }
            //cout << "--1--\n";
            if(nums.at(i) > this->localMax)
            {
                this->localMaxIdx = i;
                this->localMax = nums.at(i);
            }
            //cout << "--2--\n";
            ret.push_back(this->localMax);
        }
     
        return ret;
    }


    void maxInWindow(vector<int>& nums, int hi, int k)
    {
        //cout << hi << ' ' << k << "in maxInWindow\n";
        this->localMaxIdx = max_element(nums.begin()+hi-k+1, nums.begin()+hi+1) - nums.begin();
        this->localMax = nums.at(this->localMaxIdx);
    }


};

int main(int argc, char const *argv[])
{
    vector <int> a = {1, 2};
    cout << *max_element(a.begin(), a.begin()+2+1);
    priority_queue<int> pq;
    

    return 0;
}
