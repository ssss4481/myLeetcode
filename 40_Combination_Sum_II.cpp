#include <vector>


class Solution {
private:
    std::vector<std::vector<int>> ret;
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        this->ret = std::vector<std::vector<int>>();
        std::sort(candidates.begin(), candidates.end());

        std::vector<int> combination;
        for(int i = 0; i < candidates.size();  ++i){
            if(i > 0 && candidates[i] == candidates[i-1]){
                continue;
            }
            combination.push_back(candidates[i]);
            DFS(candidates, combination, target-candidates[i], i+1);
            combination.pop_back();
        }

        return this->ret;
        
    }

    void DFS(std::vector<int>& candidates, std::vector<int>& combination, int target, int current){
        if(target < 0){
            return;
        }
        if(target == 0){
            this->ret.push_back(combination);
            return;
        }

        for(int i = current; i < candidates.size(); ++i){
            if(i > current && candidates[i] == candidates[i-1]){
                continue;
            }
            combination.push_back(candidates[i]);
            DFS(candidates, combination, target-candidates[i], i+1);
            combination.pop_back();            
        }
    }
};