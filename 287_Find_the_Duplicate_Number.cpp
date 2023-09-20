#include <vector>
#include <unordered_set>
using namespace std;


class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        vector<char> HS(100001, 0);
        for(auto& num: nums)
        {
            if(HS.at(num) == 1)
            {
                return num;
            }
            HS.at(num) = 1;
        }     
        return -1;
    }
};