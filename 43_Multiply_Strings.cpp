#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() > num2.size()){
            num1.swap(num2);
        }
        vector<string> mul_results;







        
    }

    string multiply(string& num, int mul_digit, int zero_tail){
        int carry = 0;
        string res = num;
        for(int i = num.size()-1; i >= 0; --i){
            int digit = num[i]-'0';
            int local_result = digit*mul_digit + carry;
            carry = local_result / 10;
            res[i] = '0' + (local_result % 10);
        }

        string tail = "";
        for(int i = 1; i <= zero_tail; ++i){
            tail.push_back('0');
        }

        if(carry > 0){
            return to_string(carry) + res + tail;
        }else{
            return res + tail;
        }
    }

    string add(string& num_long, const string& num_short){
        const int m = num_long.size();
        const int n = num_short.size();




    }
};