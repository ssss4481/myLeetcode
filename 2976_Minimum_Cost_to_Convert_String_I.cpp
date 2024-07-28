#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

#define INDEX(c) c-'a'
#define N 26

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
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> distance(N, vector<long long>(N, INT_MAX));


        for(int i = 0; i < N; ++i){
            distance[i][i] = 0;
        }

        for(int i = 0; i < original.size(); ++i){
            int from = INDEX(original[i]);
            int to = INDEX(changed[i]);
            distance[from][to] = min(distance[from][to], static_cast<long long>(cost[i]));
        }

        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
                }
            }
        }

        long long result = 0;

        for(int i = 0; i < source.size(); ++i){
            if(distance[INDEX(source[i])][INDEX(target[i])] < INT_MAX){
                result += distance[INDEX(source[i])][INDEX(target[i])];
            }else{
                return -1;
            }
        }

        return result;
    }
};