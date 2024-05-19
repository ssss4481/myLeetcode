#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ai;//all the i has a string a
        vector<int> bj;//all the j has a string b
        for(int i = 0; i < s.size(); ++i){
            if(found(s, i, a)){
                ai.push_back(i);
            }
            if(found(s, i, b)){
                bj.push_back(i);
            }
        }
        
        vector<int> result;
        
        for(auto& i: ai){
            for(auto& j: bj){
                if(abs(i-j) <= k){//beautiful
                    result.push_back(i);
                    break;
                }
            }
        }
        
        return result;        
    }
    
    bool found(const string& s, int i, const string& a){
        if(s.size() - i < a.size()){
            return false;
        }
        for(int j = 0; j < a.size(); ++j){
            if(s[i] != a[j]){
                return false;
            }
            ++i;
        }
        return true;
    }
    
};