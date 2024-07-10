#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        string current_dir = "./";
        string parent_dir = "../";

        for(auto& log: logs){
            if(log != current_dir){
                if(log == parent_dir){
                    if(depth > 0){
                        --depth;
                    }
                }else{
                    ++depth;
                }
            }
        }
        return depth;
    }
};