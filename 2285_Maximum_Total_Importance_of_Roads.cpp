#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> nodes_degree(n, 0);

        for(auto& road: roads){
            int& n1 = road[0];
            int& n2 = road[1];
            ++nodes_degree[n1];
            ++nodes_degree[n2];
        }

        sort(nodes_degree.rbegin(), nodes_degree.rend());

        long long result = 0;

        for(auto& degree: nodes_degree){
            result += (degree * static_cast<long long>(n));
            --n;
        }

        return result;
    }
};