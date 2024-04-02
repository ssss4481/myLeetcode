#include <vector>
#include <string>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
private:
    std::vector<std::string> ret;

public:
    std::vector<std::string> generateParenthesis(int n) 
    {
        std::string s = "";
        backTrack(n, n, s);
        return this->ret;
    }

    void backTrack(int left, int right, std::string& s)
    {
        if(right < left || left < 0)
        {
            return;
        }

        if(left == 0 && right == 0)
        {
            this->ret.push_back(s);
        }

        s.push_back('(');
        backTrack(left-1, right, s);
        s.pop_back();
        s.push_back(')');
        backTrack(left, right-1, s);
        s.pop_back();
    }
};