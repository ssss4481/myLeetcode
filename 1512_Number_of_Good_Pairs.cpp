#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();



class Solution 
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int count = 0;
        unordered_map<int, int> table;
        for(auto& num: nums)
        {
            count += table[num];            
            ++table[num];
        }
        return count;
    }
};

class Solution2 //slow, but the nums.length <= 100
{
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int count = 0;
        int table[101]{};
        for(auto& num: nums)
        {
            count += table[num];
            ++table[num];
        }
        return count;
    }
};


int main(int argc, char const *argv[])
{
    unordered_map<int, int>a;
    ++a[0];
    cout << a[0];

    return 0;
}
