#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> info;
    info[nums[0]] = 0;
    for(int i = 1; i < nums.size(); ++i)
    {
        if(info.count(target - nums[i]))
        {
            return {info[target - nums[i]], i};
        }
        info[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> test{2, 7, 11, 15};
    vector<int> ret = twoSum(test, 9);
    cout << ret[0] << " " << ret[1] << "\n";
    return 0;
}