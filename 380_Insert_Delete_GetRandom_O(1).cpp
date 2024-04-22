#include <vector>
#include <unordered_map>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> nums_to_index;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(nums_to_index.count(val) == 1){
            return false;
        }
        nums.push_back(val);
        nums_to_index[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(nums_to_index.count(val) == 0){
            return false;
        }        
        int idx = nums_to_index[val];
        if(idx == nums.size()-1){
            nums.pop_back();
            nums_to_index.erase(val);
            return true;
        }

        std::swap(nums[idx], nums[nums.size()-1]);   
        nums_to_index[nums[idx]] = idx;
        nums.pop_back();
        nums_to_index.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */