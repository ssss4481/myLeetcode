#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {

        vector<int> numTable(2001, 0);
        vector<int> ans1;
        vector<int> ans2;
        for(auto& num: nums1)
        {
            numTable[num+1000] = 1;
        }
        for(auto& num: nums2)
        {
            if(numTable[num+1000] == 0)
            {
                ans2.push_back(num);
                numTable[num+1000] = -1;
            }
            else if(numTable[num+1000] == 1)
            {
                numTable[num+1000] = -1;             
            }
        }

        for(int i = 0; i < numTable.size(); ++i)
        {   
            if(numTable[i] == 1)
                ans1.push_back(i-1000);
        }

        return {ans1, ans2};        
    }
};


int main(int argc, char const *argv[])
{
    Solution testObj = Solution();
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6};

    auto ret = testObj.findDifference(nums1, nums2);




    return 0;
}
