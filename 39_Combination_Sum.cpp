#include <vector>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::vector<std::vector<int>> ret;

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) 
    {
        std::sort(candidates.begin(), candidates.end());  
        std::vector<int> comb;
        backtracking(candidates, comb, 0, target);
        return this->ret;
    }

    void backtracking(const std::vector<int>& candidates, std::vector<int>& comb, int current, int target)
    {
        if(target == 0)
        {
            this->ret.push_back(comb);
            return;
        }
        for(int i = current; i < candidates.size() && candidates[i] <= target; ++i)
        {
            comb.push_back(candidates[i]);
            backtracking(candidates, comb, i, target-candidates[i]);
            comb.pop_back();
        }
    }
};