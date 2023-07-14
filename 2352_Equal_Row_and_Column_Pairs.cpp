#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        int count = 0;
        map <vector<int>, int> hMap;
        for(auto& row: grid)
        {
            if(hMap.count(row) == 0)
                hMap.insert(pair<vector<int>, int>(row, 1));
            else
                hMap.at(row)++;
        }

        for(int j = 0; j < grid.size(); ++j)
        {
            vector<int> col (grid.size());
            for(int i = 0; i < grid.size(); ++i)
            {
                col[i] = grid[i][j];
            }
            if(hMap.count(col) != 0)
                count += hMap.at(col);
        }

        return count;        
    }
};



int main(int argc, char const *argv[])
{



    return 0;
}
