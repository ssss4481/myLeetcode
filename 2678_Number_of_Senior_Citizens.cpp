#include <iostream>
#include <vector>
#include <string>

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
    int countSeniors(vector<string>& details) {
        int result = 0;

        for(auto& info : details){
            int age = (info[11]-'0')*10 + (info[12]-'0');
            if(age > 60){
                ++result;
            }
        }
        return result;
    }
};