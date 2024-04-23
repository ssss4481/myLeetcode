#include <string>
#include <algorithm>


class Solution {
public:
    int longestValidParentheses(std::string s) {
        int leftCount = 0;
        int rightCount = 0;

        int ret = 0;

        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                ++leftCount;
            }else{
                ++rightCount;
            }
            if(leftCount == rightCount){
                ret = std::max(ret, leftCount*2);
            }
            if(rightCount > leftCount){
                leftCount = 0;
                rightCount = 0;
            }
        }


        leftCount = 0;
        rightCount = 0;

        for(int i = s.length()-1; i >= 0; --i){
            if(s[i] == '('){
                ++leftCount;
            }else{
                ++rightCount;
            }
            if(leftCount == rightCount){
                ret = std::max(ret, leftCount*2);
            }
            if(rightCount < leftCount){
                leftCount = 0;
                rightCount = 0;
            }
        }        

        return ret;
    }
};