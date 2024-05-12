#include <vector>
using namespace std;
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<int>& first_row = grid.front();

        for(int i = 0; i < n-1; ++i){
            if(first_row[i] == first_row[i+1]){
                return false;
            }
        }


        for(auto& row: grid){
            for(int i = 0; i < n; ++i){
                if(first_row[i] != row[i]){
                    return false;
                }
            }
        }

        return true;
        
    }
};