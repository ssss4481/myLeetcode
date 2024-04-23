#include <vector>
#include <algorithm>

class Solution {
public:
    int minRectanglesToCoverPoints(std::vector<std::vector<int>>& points, int w) {
        auto cmp = [](const std::vector<int>& a, const std::vector<int>& b){
            return a[0] < b[0];
        };
        std::sort(points.begin(), points.end());

        int count = 0;

        auto it = points.begin();

        while(it != points.end()){
            ++count;
            std::vector<int> target = {(*it)[0] + w, 0};
            it = std::upper_bound(points.begin(), points.end(), target, cmp);
        }
        return count;
    }
};