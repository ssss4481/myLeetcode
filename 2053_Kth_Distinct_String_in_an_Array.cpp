#include <iostream>
#include <string>
#include <unordered_set>
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinct;
        unordered_set<string> duplicate;

        for(auto& s : arr){
            if(distinct.count(s) == 0 && duplicate.count(s) == 0){
                distinct.insert(s);
            }else if(distinct.count(s) == 1){
                distinct.erase(s);
                duplicate.insert(s);
            }
        }

        for(auto& s : arr){
            if(distinct.count(s) == 1){
                --k;
            }
            if(k == 0){
                return s;
            }
        }
        return "";
    }
};