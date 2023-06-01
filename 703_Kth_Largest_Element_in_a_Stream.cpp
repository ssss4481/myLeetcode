#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class KthLargest 
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        for(int& num:nums)
        {
            if(this->pq.size() < k)
            {
                pq.push(num);
            }
            else if(num > this->pq.top())
            {
                this->pq.pop();
                this->pq.push(num);
            }
        }    
    }
    
    int add(int val) 
    {
        if(this->pq.size() < this->k)
        {
            pq.push(val);
        }
        else if(val > this->pq.top())
        {
            this->pq.pop();
            this->pq.push(val);
        }

        return this->pq.top();
    }
};




class KthLargest2 
{
private:
    int k;
    vector<int> arr;
public:
    KthLargest2(int k, vector<int>& nums)
    {
        this->k = k;
        sort(nums.rbegin(), nums.rend());
        this->arr = std::move(nums);        
    }
    
    int add(int val) 
    {
        this->arr.insert(std::upper_bound(arr.begin(), arr.end(), val, greater<int>()),  val);
        return this->arr[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */