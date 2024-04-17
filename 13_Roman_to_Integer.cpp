#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> value;
        
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        int num = 0;
        std::stack<char> st;
        for(auto& c: s){
            if(!st.empty() && value[st.top()] != value[c]){
                if(value[c] > value[st.top()]){
                    while(!st.empty()){
                        num -= value[st.top()];
                        st.pop();
                    }
                }else{
                    while(!st.empty()){
                        num += value[st.top()];
                        st.pop();
                    }                    
                }
            }
            st.push(c);
        }
        while(!st.empty()){
            num += value[st.top()];
            st.pop();
        }   

        return num;
    }
};