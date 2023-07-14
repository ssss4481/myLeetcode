#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> table;

        for(auto& num: nums)
        {
            if(table.count(num) == 0)
            {
                table.insert(make_pair(num, 1));
            }
            else
            {
                ++table[num];
                if(table[num] == 3)
                {
                    table.erase(num);
                }
            }
        }

        return table.begin()->first;
    }
};