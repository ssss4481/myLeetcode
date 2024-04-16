#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        permutation(nums, 0, ret);
        return ret;
    }
    
    void permutation(std::vector<int>& nums, int i, std::vector<std::vector<int>>& ret){
        if(i == nums.size()){
            ret.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); ++j){
            std::swap(nums[i], nums[j]);
            permutation(nums, i+1, ret);
            std::swap(nums[i], nums[j]);
        }
    }
};


class Solution1 
{
public: 
    // void vectorSwap(vector<int>& nums, int depth, int i)
    // {
    //     int temp = nums[depth];
    //     nums[depth] = nums[i];
    //     nums[i] = temp;
    // }

    void permutation(vector<vector<int>>& ret, vector<int>& nums, int depth)
    {
        if(depth == nums.size()-1)
        {
            ret.push_back(nums);
            return;
        }
        for(int i = depth; i < nums.size(); ++i)
        {   
            swap(nums[depth], nums[i]);
            permutation(ret, nums, depth+1);
            swap(nums[depth], nums[i]);
        }            
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ret;
        permutation(ret, nums, 0);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    //test code
    vector<vector<int>> ret;
    vector<int> t = {1, 2};
    ret.push_back(t);
    t[0] = 3;
    ret.push_back(t);

    for(vector<int>& j: ret)
    {
        for(int& n: j)
        {
            cout << n << ", ";
        }
        cout << "\n";
    }
    return 0;
}
