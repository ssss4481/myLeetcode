#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        if(nums.size() < 3)
        {
            return false;
        }

        vector<int> mins(nums.size());
        mins[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            mins[i] = min(nums[i], mins[i-1]);
        }

        stack<int> st;

        for(int i = nums.size()-1; i >= 0; --i)
        {
            if(st.empty() || nums[i] < st.top())
            {
                st.push(nums[i]);
            }
            else if(nums[i] > st.top())
            {
                while(!st.empty() && nums[i] > st.top())
                {
                    if(mins[i] < st.top())
                    {
                        return true;
                    }                                      
                    st.pop();                    
                }
                st.push(nums[i]);
            }
        }
        return false;        
    }
};



class Solution2 //TLE 
{
public:
    bool find132pattern(vector<int>& nums) 
    {
        vector<int> delta(nums.size(), 0);

        for(int t = 1; t < nums.size(); ++t)
        {          
            delta[t-1] = nums[t] - nums[t-1];
        }

        int switchIdx = -1;

        auto doTask = [&](int t)
        {
            bool up = false;
            bool down = false;
            int upSum = 0;
            int downSum = 0;
            switchIdx = -1;

            for(; t < delta.size()-1; ++t)
            {
                if(!up && !down)
                {
                    if(delta[t] > 0)
                    {
                        up = true;
                        upSum += delta[t];
                    }
                }
                else if(up && !down)
                {
                    if(delta[t] > 0)
                    {
                        upSum += delta[t];
                    }
                    else if(delta[t] < 0)
                    {
                        down = true;
                        downSum = upSum + delta[t];
                        switchIdx = t;                    
                    }
                }
                else if(down)
                {
                    if(downSum > 0 && downSum < upSum)
                    {
                        cout << downSum << " " << t << '\n';
                        return true;
                    }
                    else
                    {
                        downSum += delta[t];
                    }
                }                       
            }
            return downSum > 0 && downSum < upSum;
        };
        
        if(doTask(0))
        {
            //cout << "123\n";
            return true;
        }
        while(switchIdx != -1)
        {
            if(doTask(switchIdx))
            {
                return true;
            }
        }

        return false;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> a {-2, 1, 1, -2, 1, 1};
    cout << Solution2().find132pattern(a);
    
    return 0;
}
