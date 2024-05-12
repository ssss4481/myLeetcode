#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <climits>

using namespace std;


class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<vector<int>> pos(26, vector<int>());
        for(int i = 0; i < s.size(); ++i){
            pos[s[i]-'a'].push_back(max(abs(points[i][0]), abs(points[i][1])));
        }
        for(auto& row: pos){
            sort(row.begin(), row.end());
        }
        int range = INT_MAX;

        for(auto& row: pos){
            if(row.size() <= 1){
                continue;
            }
            range = min(range, row[1]-1);
        }
        int point_count = 0;
        for(auto& row: pos){
            if(row.size() == 0){
                continue;
            }
            if(row[0] <= range){
                ++point_count;
            }
        }
        return point_count;
    }

};