#include <iostream>
#include <vector>
#include "ListNode.hpp"

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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;

        int i = 0;
        int j = 0;

        while(true){

            matrix[i][j] = head->val;
            head = head->next;

            if(head == nullptr){
                break;
            }

            int next_i = i + dirs[d][0];
            int next_j = j + dirs[d][1];
            while(next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || matrix[next_i][next_j] != -1){
                d = (d+1)%4;
                next_i = i + dirs[d][0];
                next_j = j + dirs[d][1];
            }
            i = next_i;
            j = next_j;

        }

        return matrix;
        
    }
};