#include <stack>
#include <string>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int>  nums;
        std::stack<char> ops;

        auto myisdigit = [](char c){
            return  c >= '0' && c <= '9';
        };

        auto myatoi = [](std::string& s, int lo, int hi){
            int num = 0;
            num = s[lo]-'0';
            for(int i = lo+1; i <= hi; ++i){
                if(s[i] == ' '){
                    break;
                }
                num *=10;
                num += s[i]-'0';
            }
            return num;
        };

        s.push_back(' ');
        int lo = -1;
        for(int i = 0; i < s.length(); ++i){
            if(lo == -1){
                if(myisdigit(s[i])){
                    lo = i;
                    continue;
                }else if(s[i] != ' '){
                    ops.push(s[i]);
                }
            }else{
                if(myisdigit(s[i])){
                    continue;
                }else{
                    int b = myatoi(s, lo, i-1);
                    if(!ops.empty()){
                        if(ops.top() == '*' || ops.top() == '/'){
                            int a = nums.top();
                            nums.pop();
                            if(ops.top() == '*'){
                                nums.push(a*b);
                            }else{
                                nums.push(a/b);
                            }
                            ops.pop();
                        }else{
                            nums.push(b);
                        }
                    }else{
                        nums.push(b);
                    }
                    if(s[i] != ' '){
                        ops.push(s[i]);
                    }
                    lo = -1;
                }
            }
        }
        int res = 0;

        if(nums.size() != 1){
            while(!ops.empty()){
                if(ops.top() == '+'){
                    res += nums.top();
                }else{
                    res -= nums.top();
                }
                ops.pop();
                nums.pop();
            }
        }

        return res+nums.top();
    }
};