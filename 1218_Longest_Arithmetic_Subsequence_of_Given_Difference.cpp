#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution 
{
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        int ret = 1;
        unordered_map<int, int> hashMap;

        for(int i = 0; i < arr.size(); ++i)
        {
            int target = arr[i] - difference;
            hashMap[arr[i]] = hashMap.count(target) == 0 ? 1 : 1 + hashMap[target];
            ret = max(ret, hashMap[arr[i]]);
        }
        return ret;
    }
};