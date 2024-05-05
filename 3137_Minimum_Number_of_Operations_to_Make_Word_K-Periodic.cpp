#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> hashmap;
        int max_freq = 0;
        for(int i = 0; i < word.size(); i += k){
            string subword = word.substr(i, k);
            ++hashmap[subword];
            max_freq = max(max_freq, hashmap[subword]);
        }
        
        return word.length()/k - max_freq;
    }
};