#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

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
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> prefix;

        for(auto& n: arr1){
            while(n != 0){
                prefix.insert(n);
                n /= 10;
            }
        }

        int result = 0;
        
        for(auto& n: arr2){
            int prefix_length = static_cast<int>(to_string(n).size());
            while(n != 0){
                if(prefix_length < result){
                    break;
                }
                if(prefix.count(n) == 1){
                    result = max(result, prefix_length);
                    break;
                }
                n /= 10;
                prefix_length--;
            }            
        }

        return result;
    }
};