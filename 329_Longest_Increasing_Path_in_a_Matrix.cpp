#include <vector>
#include <iostream>
const int fast_io = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution{
private:
    std::vector<std::vector<int>> dp;
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix){

        this->dp = std::vector<std::vector<int>>(matrix.size(), std::vector<int>(matrix[0].size(), -1));
        int ret = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                ret = std::max(ret, DFS(matrix, i, j, -1));
            }
        }
        return ret;
    }

    int DFS(std::vector<std::vector<int>>& matrix, int i, int j, int parentVal){
        if(matrix[i][j] == -1 || parentVal >= matrix[i][j]){
            return 0;
        }

        if(this->dp[i][j] != -1){
            return this->dp[i][j];
        }

        int ret = 1;
        int originalVal = matrix[i][j];
        matrix[i][j] = -1;
        if(i > 0)
        {
            ret = std::max(ret, DFS(matrix, i-1, j, originalVal)+1);
        }
        if(i < matrix.size()-1)
        {
            ret = std::max(ret, DFS(matrix, i+1, j, originalVal)+1);
        }
        if(j > 0)
        {
            ret = std::max(ret, DFS(matrix, i, j-1, originalVal)+1);
        }
        if(j < matrix[0].size()-1)
        {
            ret = std::max(ret, DFS(matrix, i, j+1, originalVal)+1);
        }
        matrix[i][j] = originalVal;
        this->dp[i][j] = ret;
        return ret;
    }
};