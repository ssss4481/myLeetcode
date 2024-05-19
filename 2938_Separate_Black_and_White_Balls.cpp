#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {

        
        int one_count = 0;
        for(auto& bit: s){
            if(bit == '1'){
                ++one_count;
            }
        }
        
        if(one_count == s.size() || one_count == 0){
            return 0;
        }
        
        //01001
        //00011
        
        long long ans = 0;
        
        vector<int> zero_idx;
        for(int i = s.size()-1; i >= s.size()-one_count; --i){
            if(s[i] == '0'){
                zero_idx.push_back(i);
            }
        }
        
        int j = 0;
        for(int i = 0; i < s.size()-one_count && j < zero_idx.size(); ++i){
            if(s[i] == '1'){
                ans += zero_idx[j++]-i;
            }
        }
        return ans;
        
    }
};