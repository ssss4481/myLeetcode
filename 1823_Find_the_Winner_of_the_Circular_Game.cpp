#include <queue>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>Q;
        for(int i = 1; i <= n; ++i){
            Q.push(i);
        }

        while(Q.size() > 1){
            for(int i = 1; i < k; ++i){
                Q.push(Q.front());
                Q.pop();
            }
            Q.pop();
        }

        return Q.front();
    }
};