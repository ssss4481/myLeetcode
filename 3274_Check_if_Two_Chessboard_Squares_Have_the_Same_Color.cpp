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
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        auto color = [](const string& c){
            return (c[0]-'a' + c[1]-'1')%2;
        };

        return color(coordinate1) == color(coordinate2);
    }
};