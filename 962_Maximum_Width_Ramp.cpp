#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;

        for(int i = 0; i < nums.size(); i++){
            if(st.empty() || nums[i] <= nums[st.top()]){
                st.push(i);
            }
        }


        int result = 0;
        int i = nums.size()-1;

        while(!st.empty() && i >= st.top()){
            if(nums[i] >= nums[st.top()]){
                result = max(result, i - st.top());
                st.pop();
            }else{
                i--;
            }
        }

        return result;
    }
};