#include <iostream>
#include <vector>
#include <random>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
private:
    vector<int> init;
    vector<int> current;
    default_random_engine generator;
    uniform_int_distribution<int> distribution;    
public:
    Solution(vector<int>& nums) {
        init = nums;
        current = nums;
        distribution = uniform_int_distribution<int>(0, nums.size()-1);
    }
    
    vector<int> reset() {
        current = init;
        return current;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < current.size(); ++i){
            swap(current[i], current[distribution(generator)]);
        }
        return current;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */