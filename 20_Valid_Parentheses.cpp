#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> BracketStack;
        
        for(auto& c: s){
            if(isLeft(c)){
                BracketStack.push(c);
            }else{
                if(BracketStack.empty() || leftBracket(c) != BracketStack.top()){
                    return false;
                }
                BracketStack.pop();
            }
        }
        return BracketStack.empty();
    }

    bool isLeft(char c){
        return c == '(' || c == '[' || c == '{';
    }

    char leftBracket(char right){
        if(right == ')'){
            return '(';
        }

        if(right == ']'){
            return '[';
        }

        if(right == '}'){
            return '{';
        }
        return 'x';
    }
};
