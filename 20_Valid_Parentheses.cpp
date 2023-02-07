#include <iostream>
#include <stack>
#include <set>
using namespace std;

class Solution
{
public:
    char returnLeftParentheses(char rP)
    {
        switch (rP)
        {
            case ')':
                return '(';
            case ']':
                return '[';
            case '}':
                return '{';
            default:
                return 'x';
        }
    }
    bool isValid(string s)
    {
        stack<char> leftParenthesesStack;
        set<char> leftSide ({'(', '[', '{'});

        for(int i = 0; i < s.length(); ++i)
        {
            if(leftSide.count(s[i]) == 1)
            {
                //cout << "push" << s[i] << "\n";
                leftParenthesesStack.push(s[i]);
                continue;
            }
            if(leftParenthesesStack.empty() || (leftParenthesesStack.top() != this->returnLeftParentheses(s[i])))
            {
                //cout << "F1\n";
                return false;
            }
            leftParenthesesStack.pop();
        }
        if(!leftParenthesesStack.empty())
        {
            //cout << "F2\n";
            return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol = Solution();

    sol.isValid("()");

    return 0;
}
