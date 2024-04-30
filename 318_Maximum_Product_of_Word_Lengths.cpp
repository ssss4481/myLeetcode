#include <vector>
#include <string>
#include <algorithm>


#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int maxProduct(std::vector<std::string>& words) {
        std::vector<unsigned int> bits(words.size(), 0);
        auto cmp = [](const std::string& s1, const std::string& s2){
            return s1.length() > s2.length();
        };

        std::sort(words.begin(), words.end(), cmp);

        for(int i = 0; i < words.size(); ++i){
            for(auto& c: words[i]){
                bits[i] |= (1 << (c-'a'));
            }
        }        

        int ret = 0;

        for(int i = 0; i < words.size(); ++i){
            for(int j = i+1; j < words.size(); ++j){
                if((bits[i] & bits[j]) == 0){
                    ret = std::max(ret, static_cast<int>(words[i].length()*words[j].length()));
                    break;
                }

            }
        }
        return ret;
    }
};