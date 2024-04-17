#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef std::pair<int, int> TempAndIndex;

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> ret(temperatures.size(), 0);
        std::stack<TempAndIndex> st;
        
        st.push({temperatures[0], 0});
        for(int i = 1; i < temperatures.size(); ++i){
            if(!st.empty() && temperatures[i] > st.top().first){
                while(!st.empty() && st.top().first < temperatures[i]){
                    auto p = st.top();
                    ret[p.second] = i - p.second;
                    st.pop();
                }
            }
            st.push({temperatures[i], i});
        }
        return ret;
    }
};