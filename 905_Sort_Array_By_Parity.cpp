#include <vector>
#include <iostream>
using namespace std;


class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        const int n = nums.size();
        int lo = -1;
        int hi = n;
        while(lo < hi)
        {
            while(lo < n-1 && nums[++lo] % 2 == 0);
            while(hi > 0 && nums[--hi] % 2 == 1);
            if(lo < hi)
            {
                swap(nums[lo], nums[hi]);
            }                   
        }
        return nums;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a{1, 2};
    swap(a[0], a[1]);
    cout << a[0];


    return 0;
}
