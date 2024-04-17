#include <string>


class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int ai = a.size()-1;
        int bi = b.size()-1;

        std::string ret = "";

        bool c = false;
        while(ai >= 0 || bi >= 0){
            int bits = 0;
            if(ai >= 0 && a[ai--] == '1'){
                ++bits;
            }
            if(bi >= 0 && b[bi--] == '1'){
                ++bits;
            }
            if(c){
                ++bits;
            }

            switch (bits){
                case 0: {
                    ret.push_back('0');
                    break;
                }
                case 1: {
                    ret.push_back('1');
                    break;
                }
                case 2:{
                    ret.push_back('0');
                    break;
                }
                case 3:{
                    ret.push_back('1');
                    break;
                }
            }

            if(bits >= 2){
                c = true;
            }
            else{
                c = false;
            }
            
        }

        if(c){
            ret.push_back('1');
        }

        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};