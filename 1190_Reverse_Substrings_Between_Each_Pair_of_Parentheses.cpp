#include <string>
#include <stack>
#include <unordered_map>
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
    string reverseParentheses(string s) {
        stack<int> leftbr;
        unordered_map<int, int> gate;
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                leftbr.push(i);
            }else if(s[i] == ')'){
                int l = leftbr.top();
                leftbr.pop();
                gate[l] = i;
                gate[i] = l;
            }
        }

        int size = s.size() - gate.size();
        bool mode = true;
        string result;
        result.reserve(size);
        for(int i = 0; size > 0;){
            if(s[i] == '(' || s[i] == ')'){
                i = gate[i];
                mode = !mode;
            }else{
                result.push_back(s[i]);
                --size;
            }

            if(mode){
                ++i;
            }else{
                --i;
            }
        }

        return result;
    }
};

class Solution2 {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int> leftbr;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                leftbr.push(i);
            }else if(s[i] == ')'){
                reverse(s.begin()+leftbr.top(), s.begin()+i);
                leftbr.pop();
            }
        }

        result.reserve(s.size());
        for(auto& c: s){
            if(c != '(' && c != ')'){
                result.push_back(c);
            }
        }
        return result;
    }
};