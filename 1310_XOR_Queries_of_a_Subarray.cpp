#include <iostream>
#include <vector>

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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();
        vector<int> prefix_xor(n, 0);
        prefix_xor.front() = arr.front();

        for(int i = 1; i < n; ++i){
            prefix_xor[i] = arr[i] ^ prefix_xor[i-1];
        }

        vector<int> result;

        for(auto& q: queries){
            int left = q[0];
            int right = q[1];

            if(left > 0){
                result.push_back(prefix_xor[right] ^ prefix_xor[left-1]);
            }else{
                result.push_back(prefix_xor[right]);
            }
        }

        return result;
    }
};