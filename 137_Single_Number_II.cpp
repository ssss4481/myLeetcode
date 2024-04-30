#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int count[32] = {0};
        for(unsigned int n : nums){
            int i = 0;
            while(n != 0){
                if((n & 1) == 1){
                    ++count[i];
                }
                ++i;
                n >>= 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; ++i){
            if(count[i] % 3 != 0){
                res += (1 << i);
            }
        }
        return res;
    }
};

using namespace std;

class Solution1 
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