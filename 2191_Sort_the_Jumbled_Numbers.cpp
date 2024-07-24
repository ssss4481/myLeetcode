#include <vector>
#include <algorithm>
#include <numeric>
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
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        const int n = nums.size();

        vector<int> transformation(n);
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        for(int i = 0; i < n; i++){
            transformation[i] = transform(nums[i], mapping);
        }

        auto cmp = [&](int i, int j){
            if(transformation[i] == transformation[j]){
                return i < j;
            }
            return transformation[i] < transformation[j];
        };

        sort(indices.begin(), indices.end(), cmp);

        for(int i = 0; i < n; i++){
            transformation[i] = nums[indices[i]];
        }

        return transformation;
    }

    int transform(int num, vector<int>& mapping)
    {
        int result = 0;
        int digit = 1;

        do{
            result += (mapping[(num)%10])*digit;
            num /= 10;
            digit *= 10 ;
        }while(num > 0);

        return result;
    }    

};