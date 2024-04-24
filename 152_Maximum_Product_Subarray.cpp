#include <vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int product = 1;
        int start = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            product *= nums[i];
            res = std::max(res, product);
            if(product == 0){
                product = 1;
            }
        }

        product = 1;
        for(int i = nums.size()-1; i >= 0; --i){
            product *= nums[i];
            res = std::max(res, product);
            if(product == 0){
                product = 1;
            }
        }

        return res;
    }
};