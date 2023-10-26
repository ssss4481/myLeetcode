#include <iostream>
#include <stack>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int kthGrammar(int n, int k) 
    {
        long long int num = pow(2, n-1) + k-1;
        std::stack<bool> toLeft;
        while(num != 1)
        {
            if(num & 1 == 1)
            {
                toLeft.push(false);
            }
            else
            {
                toLeft.push(true);
            }
            num >>= 1;
        }

        bool isZero = true;
        while(!toLeft.empty())
        {
            if(!toLeft.top())
            {            
                isZero = !isZero;
            }
            toLeft.pop();
        }
        
        return isZero ? 0 : 1;        
    }

    int pow(int base, int power)
    {
        if(power == 0)
        {
            return 1;
        }
        if(power == 1)
        {
            return base;
        }

        if(power & 1 == 1)
        {
            return base*pow(base*base, power/2);
        }
        else
        {
            return pow(base*base, power/2);
        }
    }
};