#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) 
    {
        vector<pair<int, int>> v_f_arr(201);

        for(int i = -100; i <= 100; i++){
            v_f_arr[i+100] = {i, 0};
        }

        for(auto& n: nums){
            v_f_arr[n+100].second++;
        }

        auto cmp = [](const pair<int, int>& v_f1, const pair<int, int>& v_f2){
            if(v_f1.second == v_f2.second){
                return v_f1.first > v_f2.first;
            }
            return v_f1.second < v_f2.second;
        };

        sort(v_f_arr.begin(), v_f_arr.end(), cmp);

        int pos = 0;
        auto it = v_f_arr.begin();

        while(pos < nums.size()){
            const int v = (*it).first;
            const int f = (*it).second;
            for(int i = 0; i < f; i++){
                nums[pos++] = v;
            }
            ++it;
        }

        return nums;
    }
};