#include <vector>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        arr.push_back(INT_MAX);
        int r = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;

        while(k > 0 && l >= 0){
            if(x - arr[l] <= arr[r] - x){
                --l;
            }else{
                ++r;
            }
            --k;
        }
        r += k;
        return std::vector<int>(arr.begin()+l+1, arr.begin()+r);
    }
};