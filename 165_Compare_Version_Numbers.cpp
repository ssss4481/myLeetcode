#include <vector>
#include <string>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::vector<int> dot_index1 = {-1};
        std::vector<int> dot_index2 = {-1};

        auto find_dot = [](std::vector<int>& dot_index, std::string& version){
            for(int i = 0; i < version.size(); ++i){
                if(version[i] == '.'){
                    dot_index.push_back(i);
                }
            }
            dot_index.push_back(version.size());            
        };

        find_dot(dot_index1, version1);
        find_dot(dot_index2, version2);

        bool flip = false;

        if(dot_index1.size() > dot_index2.size()){
            flip = true;
            version1.swap(version2);
            dot_index1.swap(dot_index2);
        }

        int res = 0;

        for(int i = 0; i < dot_index2.size()-1; ++i){
            int v1;
            int v2;
            if(i < dot_index1.size()-1){
                v1 = stoi(version1.substr(dot_index1[i]+1, dot_index1[i+1]-dot_index1[i]-1));
            }else{
                v1 = 0;
            }
            v2 = stoi(version2.substr(dot_index2[i]+1, dot_index2[i+1]-dot_index2[i]-1));
            if(v1 < v2){
                res = -1;
                break;
            }else if(v1 > v2){
                res = 1;
                break;
            }
        }

        return flip ? -res : res;
    }
};