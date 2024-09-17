#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> dict;
        split_to_dict(dict, s1);
        split_to_dict(dict, s2);

        vector<string> result;

        for(auto& p : dict){
            if(p.second == 1){
                result.emplace_back(p.first);
            }
        }

        return result;
    }

    void split_to_dict(unordered_map<string, int>& dict, string& s){

        stringstream ss(s);
        string word;
        while(ss >> word){
            dict[word]++;
        }
    }

};