#include <vector>
#include <iostream>
static const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int n = arr.size();
        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        for(int i = 1; i < n+1; ++i){
            prefix[i] = arr[i-1] ^ prefix[i-1];
        }

        for(int i = n-1; i >= 0; --i){
            suffix[i] = suffix[i+1]^arr[i];
        }

        int result = 0;
        for(int j = 1; j < n; ++j){
            for(int i = 0; i < j ; ++i){
                for(int k = n-1; k >= j; --k){
                    int a = prefix[j] ^ prefix[i];
                    int b = suffix[j] ^ suffix[k+1];
                    if(a == b){
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};