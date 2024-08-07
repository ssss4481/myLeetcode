#include <iostream>
#include <string>
#include <vector>
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
    int minimumPushes(string word) {
        vector<int> counts(26, 0);

        for(auto& c : word){
            ++counts[c-'a'];
        }

        sort(counts.rbegin(), counts.rend());

        int result = 0;
        int quota = 8;
        int cost = 1;

        for(auto& count: counts){
            if(count == 0){
                break;
            }

            result += count*cost;

            if(--quota == 0){
                quota = 8;
                ++cost;
            }
        }

        return result;
    }
};