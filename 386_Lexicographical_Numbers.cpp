#include <vector>
#include <iostream>

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
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        for(int i = 1; i <= 9; ++i){
            DFS(result, n, i);
        }
        return result;
    }
    void DFS(vector<int>& result, int n, int cur){
        result.emplace_back(cur);
        for(int i = 0; i <= 9; ++i){
            int next = cur*10 + i;
            if(next <= n){
                DFS(result, n, next);
            }
        }
    }
};