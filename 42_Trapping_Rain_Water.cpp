#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>;

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();



class Solution {
public:
    int trap(std::vector<int>& height){
        std::stack<int> pos;
        int ans = 0;
        int i = 0;

        while(i < height.size()){
            if(pos.empty() || height[pos.top()] >= height[i]){
                pos.push(i);
                ++i;
            }else{
                int current = pos.top();
                pos.pop();
                if(pos.empty())	{
                    continue;
                }
                ans += (std::min(height[pos.top()], height[i]) - height[current]) * (i - pos.top() -1);
            }
	    }
    	return ans;
    }
};



class Solution2 //O(1) space
{
public:

    int trap(std::vector<int>& height) 
    {
        const int n = height.size();
        int LMax = height.front();
        int RMax = height.back();
        int lo = 0;
        int hi = n-1;
        int water = 0;

        while(lo < hi)
        {
            if(LMax <= RMax)
            {
                water += LMax - height[lo];
                ++lo;
                LMax= std::max(LMax, height[lo]);
            }
            else
            {
                water += RMax - height[hi];
                --hi;
                RMax = std::max(RMax, height[hi]);
            }
        }
        return water;
    }
};

class Solution1 
{
public:

    int trap(std::vector<int>& height) 
    {
        const int n = height.size();
        std::vector<int> LeftHeight(n);
        std::vector<int> RightHeight(n);
        
        LeftHeight[0] = height[0];
        RightHeight[n-1] = height[n-1];

        for(int i = 1; i < n; ++i)
        {
            LeftHeight[i] = std::max(height[i-1], LeftHeight[i-1]);
        }

        for(int i = n-2; i >= 0; --i)
        {
            RightHeight[i] = std::max(height[i+1], RightHeight[i+1]);
        }

        int water = 0;

        for(int i = 1; i < n-1; ++i)
        {
            int acc = std::min(LeftHeight[i], RightHeight[i])-height[i];
            if(acc > 0)
            {
                water += acc;
            }
        }

        return water;
    }
};