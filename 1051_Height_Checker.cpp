#include <vector>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        const int n = heights.size();
        vector<int> h = heights;
        sort(h.begin(), h.end());
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(heights[i] != h[i]){
                ++count;
            }

        }
        return count;
    }
};