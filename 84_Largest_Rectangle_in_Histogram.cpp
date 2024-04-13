#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {

        int ans = 0;
        std::stack<int> position_stack;

        heights.push_back(0);

        for(int i = 0; i < heights.size(); ++i){
            while(!position_stack.empty() && heights[position_stack.top()] >= heights[i])
            {
                int current_position = position_stack.top();
                int current_height = heights[current_position];
                position_stack.pop();
                int length;

                if(position_stack.empty()){
                    length = i;
                }else{
                    length = i - position_stack.top()-1;
                }
                ans = std::max(ans, current_height*length);
            }
            position_stack.push(i);
        }

        return ans;        
    }
};
