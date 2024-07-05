#include <vector>
#include <unordered_map>
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> result;
        if(nums1.size() < nums2.size()){
            nums1.swap(nums2);
        }

        for(auto& n : nums1){
            ++count[n];
        }
        for(auto& n : nums2){
            if(count[n] > 0){
                result.emplace_back(n);
                --count[n];
            }
        }
        return result;
        
    }
};