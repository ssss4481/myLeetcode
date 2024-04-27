#include <string>
#include <vector>
#include <numeric>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int findRotateSteps(std::string ring, std::string key) {
        const int n = ring.length();

        std::vector<std::vector<int>> pos(26, std::vector<int>());

        for(int i = 0; i < n; ++i){
            pos[ring[i]-'a'].push_back(i);//record all the valid postion of each character 
        }

        std::vector<int> current_pos = {0};//Current position, and it is 0 at first.
        std::vector<int> dp = {0};//Optimal for all the possible path, it is also 0 at first.
        for(int i = 0; i < key.length(); ++i){
            std::vector<int>& next_pos = pos[key[i]-'a'];//The positions where we can spell the next character.
            std::vector<int> next_dp(pos[key[i]-'a'].size(), INT_MAX);//Optimal cost of all the possible next positions.

            for(int j = 0; j < next_dp.size(); ++j){
                for(int k = 0; k < dp.size(); ++k){
                    int cost = dp[k] + std::min(abs(next_pos[j]-current_pos[k]), n - abs(next_pos[j]-current_pos[k]));
                    //the cost of moving to next_pos[j] from curent_pos[k] is dp[k] + rotation cost
                    //the rotation coast is min(abs(next_pos[j]-current_pos[k]), n - abs(next_pos[j]-current_pos[k])) because it is a ring.
                    next_dp[j] = std::min(next_dp[j], cost);//get the optimal one
                }
            }
            current_pos = next_pos; // update position
            dp.swap(next_dp); //update cost
        }

        return (*std::min_element(dp.begin(), dp.end()))+key.length(); //cost is the optimal one in dp, and plus the pressing cost(key.length()).
    }
};
