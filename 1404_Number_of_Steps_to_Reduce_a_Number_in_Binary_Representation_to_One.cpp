#include <string>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int step = 0;
        while(s != "1"){
            ++step;
            if(s.back() == '1'){
                bool done = false;
                for(int i = s.size()-1; i >= 0; --i){
                    if(s[i] == '1'){
                        s[i] = '0';
                    }else{
                        done = true;
                        s[i] = '1';
                        break;
                    }
                }
                if(!done){
                    s = "1" + s;
                }
            }else{
                s.pop_back();
            }
        }
        return step;
    }
};