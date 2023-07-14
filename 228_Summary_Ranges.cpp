#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {        
        vector<string> ret;

        if(nums.size() == 0)
            return ret;
        
        int firstNum = nums[0];
        int secondNum = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            if(static_cast<long long>(nums[i]) - secondNum <= 1)
                secondNum = nums[i];
            else
            {
                
                if(firstNum == secondNum)
                    ret.push_back(to_string(firstNum));
                else
                    ret.push_back(to_string(firstNum) + "->" + to_string(secondNum));

                if(i < nums.size())
                {
                    firstNum = nums[i];
                    secondNum = nums[i];
                }
            }
        }

        if(firstNum == secondNum)
            ret.push_back(to_string(firstNum));
        else
            ret.push_back(to_string(firstNum) + "->" + to_string(secondNum));

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    
        // initialize an integer

    cout << to_string(0) + "->" + to_string(3);
    

    return 0;
}
