#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution 
{
public:
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        const int n = static_cast<int>(nums.size());
        const int scope = 1 + k + k;
        vector<int> ret (n, -1);
        
        if(scope > n)
        {            
            return ret;
        }
        
        if(scope == 1)
        {
            return nums;
        }        

        long long sum = accumulate(nums.begin(), nums.begin()+scope, static_cast<long long>(0));

        for(int i = k; i < n-k; ++i)
        {
            ret.at(i) = sum/scope;            
            try
            {
                sum -= nums.at(i-k);
                sum += nums.at(i+k+1);
            }
            catch (const out_of_range& e)
            {
                break;
            }
        }      

        return ret;
    }
};



int main(int argc, char const *argv[])
{
    vector<int> a {1, 2, 3};
    
    cout << accumulate(a.begin(), a.begin()+1, 0) << '\n';

    return 0;
}
