#include <vector>
#include <stack>
#include <algorithm>


class Solution 
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        int ans = 0;
        std::vector<int> heights(matrix[0].size(), 0);	
        for(auto& row: matrix){
            for(int i = 0; i < row.size(); ++i){
                if(row[i] == '1'){
                    ++heights[i]; 
                }else{
                    heights[i] = 0;
                }
            }
            ans = std::max(ans, largestRectangleArea(heights));
        }
        return ans;
    }

    int largestRectangleArea(std::vector<int>& heights) {
        int ans = 0;
        heights.push_back(0);
        std::stack<int> position_stack;
        position_stack.push(0);

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
