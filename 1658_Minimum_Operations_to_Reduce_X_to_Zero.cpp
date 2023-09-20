#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

typedef long long int LL;

class Solution
{
public:

    int minOperations(vector<int>& nums, int x) 
    {        
        const int n = nums.size();

        LL target = accumulate(nums.begin(), nums.end(), LL(0)) - x;

        if(target == 0)
        {
            return n;
        }

        int left = 0;
        int right = 0;
        LL current = nums[0];

        int length = -1;

        while(right < n)
        {
            if(current < target)
            {
                ++right;
                if(right < n)
                {
                    current += nums[right];               
                }
            }
            else if(current > target)
            {
                current -= nums[left];
                ++left;
                if(left > right)
                {
                    right = left;
                    if(left < n)
                    {
                        current = nums[left];
                    }
                }
            }
            else
            {
                length = max(length, right-left+1);
                ++right;
                if(right < n)
                {
                    current += nums[right];               
                }
            }
        }
        return (length == -1) ? -1 : n-length;      
    }
};







class Solution3 //TLE
{
public:
    unordered_map<int, unordered_map<int, int>> dp;

    void operation(vector<int>& nums, int i, int j, int x)
    {
        if(this->dp.count(i) == 0)
        {
            this->dp[i] = unordered_map<int, int>();
        }

        if(this->dp[i].count(j) != 0)
        {
            return;
        }



        if(x == 0)
        {
            this->dp[i][j] = 0;
            return;
        }    

        if(x < 0 || (i == j && x != nums[i]))
        {
            this->dp[i][j] = -1;
            return;
        }

        if(i == j && x == nums[i])
        {
            this->dp[i][j] = 1;
            return;
        }   

        this->operation(nums, i+1, j, x-nums[i]);
        this->operation(nums, i, j-1, x-nums[j]);

        int& left = this->dp[i+1][j];
        int& right = this->dp[i][j-1];

        if(left == -1 && right == -1)
        {
            this->dp[i][j] = -1;
        }
        else if(left == -1)
        {
            this->dp[i][j] = right+1;
        }
        else if(right == -1)
        {
            this->dp[i][j] = left+1;
        }
        else
        {
            this->dp[i][j] = min(left, right)+1;
        }
    }

    int minOperations(vector<int>& nums, int x) 
    {        
        this->operation(nums, 0, nums.size()-1, x);
        return this->dp[0][nums.size()-1];        
    }
};




class Solution2 //MLE
{
public:
    vector<vector<int>> dp;

    void operation(vector<int>& nums, int i, int j, int x)
    {
        if(x == 0)
        {
            this->dp[i][j] = 0;
            return;
        }    

        if(x < 0 || (i == j && x != nums[i]))
        {
            this->dp[i][j] = -1;
            return;
        }

        if(i == j && x == nums[i])
        {
            this->dp[i][j] = 1;
            return;
        }

        if(this->dp[i][j] != -2)
        {
            return;
        }        

        this->operation(nums, i+1, j, x-nums[i]);
        this->operation(nums, i, j-1, x-nums[j]);

        int& left = this->dp[i+1][j];
        int& right = this->dp[i][j-1];

        if(left == -1 && right == -1)
        {
            this->dp[i][j] = -1;
        }
        else if(left == -1)
        {
            this->dp[i][j] = right+1;
        }
        else if(right == -1)
        {
            this->dp[i][j] = left+1;
        }
        else
        {
            this->dp[i][j] = min(left, right)+1;
        }
    }

    int minOperations(vector<int>& nums, int x) 
    {
        this->dp = vector<vector<int>> (nums.size(), vector<int>(nums.size(), -2));
        this->operation(nums, 0, nums.size()-1, x);
        return this->dp[0].back();        
    }
};



class Solution1 //recursive TLE
{
public:
    int operation(vector<int>& nums, int i, int j, int x)
    {
        if(x < 0 || (i > j && x > 0))
        {
            return -1;
        }

        if(x == 0)
        {
            return 0;
        }

        int left = operation(nums, i+1, j, x-nums[i]);
        int right = operation(nums, i, j-1, x-nums[j]);

        if(left == -1 && right == -1)
        {
            return -1;
        }
        else if(left == -1)
        {
            return right + 1;
        }
        else if(right == -1)
        {
            return left + 1;
        }
        else
        {
            return min(left, right)+1;
        }
    }

    int minOperations(vector<int>& nums, int x) 
    {
        return this->operation(nums, 0, nums.size()-1, x);        
    }
};